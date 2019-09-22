#include "mfcinqt_demo.h"
#include "crtdbg.h"

#define FLUSH_PLOT_INTERVAL 10
#define INPUT_RANGE			10
#define VIEW_SIZE_OF_MAP	1

MfcInQt_Demo::MfcInQt_Demo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	//_CrtSetBreakAlloc(21547);
	ui.setupUi(this);
	setWindowIcon(QIcon(":/MfcInQt_Demo/Resources/plot.ico"));
	setWindowTitle("plotData");

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));

	m_hFile = 0;
	m_hMap = 0;
	lpbMapAddress = NULL;
	dataFrame = 0;

	HWND wnd = (HWND)ui.label->winId();

	m_scope.Open(wnd);
	m_scope.Channels.Add(3);
	m_scope.Channels[0].Name = "CH0";
	m_scope.Channels[1].Name = "CH1";
	m_scope.Channels[2].Name = "CH2";
	m_scope.Channels[3].Name = "CH3";
	m_scope.SizeLimit = 1025;
	m_scope.XAxis.Max.Mode = mamOffset;
	m_scope.XAxis.Max.Value = 1024;
	m_scope.XAxis.Max.AutoScale = false;

	VCL_Loaded();
}

MfcInQt_Demo::~MfcInQt_Demo()
{

}

void MfcInQt_Demo::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"),
													QDesktopServices::storageLocation(QDesktopServices::DesktopLocation),
													QString("DAT(*.dat)"));
	ui.file->setText(fileName);
	LPCWSTR m_FileName = reinterpret_cast<const wchar_t *>(fileName.utf16());
	m_hFile = CreateFile(m_FileName, GENERIC_READ, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hFile == INVALID_HANDLE_VALUE)
	{
		QMessageBox::warning(this, "Exception", QString::fromLocal8Bit("创建内存映射文件失败"));
		return;
	}
	m_hMap = CreateFileMapping(m_hFile, NULL, PAGE_READONLY, 0, 511 * 1024 * 1024, NULL);
	if (m_hMap == NULL)
	{
		QMessageBox::warning(this, "Exception", QString::fromLocal8Bit("创建文件映射对象失败"));
		CloseHandle(m_hFile);
		return;
	}
	lpbMapAddress = (PUCHAR)MapViewOfFile(m_hMap, FILE_MAP_READ, 0, 0, VIEW_SIZE_OF_MAP * 1024 * 1024);
	if (lpbMapAddress == NULL)
	{
		QMessageBox::warning(this, "Exception", QString::fromLocal8Bit("映射文件失败"));
		CloseHandle(m_hMap);
		CloseHandle(m_hFile);
		return;
	}
	timer->start(FLUSH_PLOT_INTERVAL);
}

void MfcInQt_Demo::updatePlot()
{
	if (ui.CH0->isChecked())
	{
		float a = (float)(lpbMapAddress[3] * 256 + lpbMapAddress[2]);
		m_scope.Channels[0].Data.AddYPoint(a*INPUT_RANGE / 4096 - INPUT_RANGE / 2);
	}
	else
	{
		m_scope.Channels[0].Data.AddYPoint(0, true);
	}
	if (ui.CH1->isChecked())
	{
		float a = (float)(lpbMapAddress[1] * 256 + lpbMapAddress[0] - 4096);
		m_scope.Channels[1].Data.AddYPoint(a*INPUT_RANGE / 4096 - INPUT_RANGE / 2);
	}
	else
	{
		m_scope.Channels[1].Data.AddYPoint(0, true);
	}
	if (ui.CH2->isChecked())
	{
		float a = (float)(lpbMapAddress[7] * 256 + lpbMapAddress[6] - 4096*2);
		m_scope.Channels[2].Data.AddYPoint(a*INPUT_RANGE / 4096 - INPUT_RANGE / 2);
	}
	else
	{
		m_scope.Channels[2].Data.AddYPoint(0, true);
	}
	if (ui.CH3->isChecked())
	{
		float a = (float)(lpbMapAddress[5] * 256 + lpbMapAddress[4] - 4096 * 3);
		m_scope.Channels[3].Data.AddYPoint(a*INPUT_RANGE / 4096 - INPUT_RANGE / 2);
	}
	else
	{
		m_scope.Channels[3].Data.AddYPoint(0, true);
	}
	dataFrame++;
	lpbMapAddress += 8;
	if (dataFrame == VIEW_SIZE_OF_MAP*1024*1024/8)
	{
		timer->stop();
	}
}

void MfcInQt_Demo::closeEvent(QCloseEvent *event)
{
	if (timer->isActive())
	{
		CloseHandle(m_hMap);
		CloseHandle(m_hFile);
	}
}
