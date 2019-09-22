/********************************************************************************
** Form generated from reading UI file 'mfcinqt_demo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MFCINQT_DEMO_H
#define UI_MFCINQT_DEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MfcInQt_DemoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *CH0;
    QCheckBox *CH1;
    QCheckBox *CH2;
    QCheckBox *CH3;
    QPushButton *open;
    QLabel *file;

    void setupUi(QMainWindow *MfcInQt_DemoClass)
    {
        if (MfcInQt_DemoClass->objectName().isEmpty())
            MfcInQt_DemoClass->setObjectName(QString::fromUtf8("MfcInQt_DemoClass"));
        MfcInQt_DemoClass->resize(801, 532);
        centralWidget = new QWidget(MfcInQt_DemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(790, 500));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CH0 = new QCheckBox(centralWidget);
        CH0->setObjectName(QString::fromUtf8("CH0"));
        CH0->setChecked(true);

        horizontalLayout->addWidget(CH0);

        CH1 = new QCheckBox(centralWidget);
        CH1->setObjectName(QString::fromUtf8("CH1"));
        CH1->setChecked(true);

        horizontalLayout->addWidget(CH1);

        CH2 = new QCheckBox(centralWidget);
        CH2->setObjectName(QString::fromUtf8("CH2"));
        CH2->setChecked(true);

        horizontalLayout->addWidget(CH2);

        CH3 = new QCheckBox(centralWidget);
        CH3->setObjectName(QString::fromUtf8("CH3"));
        CH3->setChecked(true);

        horizontalLayout->addWidget(CH3);

        open = new QPushButton(centralWidget);
        open->setObjectName(QString::fromUtf8("open"));

        horizontalLayout->addWidget(open);

        file = new QLabel(centralWidget);
        file->setObjectName(QString::fromUtf8("file"));

        horizontalLayout->addWidget(file);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 9);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MfcInQt_DemoClass->setCentralWidget(centralWidget);

        retranslateUi(MfcInQt_DemoClass);
        QObject::connect(open, SIGNAL(clicked()), MfcInQt_DemoClass, SLOT(openFile()));

        QMetaObject::connectSlotsByName(MfcInQt_DemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MfcInQt_DemoClass)
    {
        MfcInQt_DemoClass->setWindowTitle(QApplication::translate("MfcInQt_DemoClass", "MfcInQt_Demo", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        CH0->setText(QApplication::translate("MfcInQt_DemoClass", "CH0", 0, QApplication::UnicodeUTF8));
        CH1->setText(QApplication::translate("MfcInQt_DemoClass", "CH1", 0, QApplication::UnicodeUTF8));
        CH2->setText(QApplication::translate("MfcInQt_DemoClass", "CH2", 0, QApplication::UnicodeUTF8));
        CH3->setText(QApplication::translate("MfcInQt_DemoClass", "CH3", 0, QApplication::UnicodeUTF8));
        open->setText(QApplication::translate("MfcInQt_DemoClass", "\346\211\223\345\274\200\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        file->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MfcInQt_DemoClass: public Ui_MfcInQt_DemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MFCINQT_DEMO_H
