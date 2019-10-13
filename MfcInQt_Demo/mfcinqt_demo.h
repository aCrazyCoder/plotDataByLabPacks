#ifndef MFCINQT_DEMO_H
#define MFCINQT_DEMO_H

#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QTimer>
#include "ui_mfcinqt_demo.h"
#include "CSLScope.h"

class MfcInQt_Demo : public QMainWindow
{
	Q_OBJECT

public:
	MfcInQt_Demo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MfcInQt_Demo();

private:
	Ui::MfcInQt_DemoClass ui;

	CTSLScope m_scope;
	QTimer* timer;
	UINT dataFrame;
	HANDLE m_hFile;
	HANDLE m_hMap;
	PUCHAR lpbMapAddress;

	USHORT dataType;

private slots:
	void openFile();
	void updateAllDataPlot();
	void updateROIDataPlot();
	void updateOBPDataPlot();

protected:
	void closeEvent(QCloseEvent *event);
};

#endif // MFCINQT_DEMO_H
