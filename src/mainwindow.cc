#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) { setupUi(); }

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(433, 307);
    actionPrintImage = new QAction(this);
    actionPrintImage->setObjectName(QString::fromUtf8("actionPrintImage"));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/print"), QSize(), QIcon::Normal, QIcon::Off);
    actionPrintImage->setIcon(icon);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    scrollArea = new QScrollArea(this);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setAlignment(Qt::AlignCenter);
    labelView = new QLabel();
    labelView->setObjectName(QString::fromUtf8("labelView"));
    labelView->setGeometry(QRect(0, 0, 431, 280));
    QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelView->sizePolicy().hasHeightForWidth());
    labelView->setSizePolicy(sizePolicy);
    labelView->setContextMenuPolicy(Qt::ActionsContextMenu);
    labelView->setScaledContents(true);
    scrollArea->setWidget(labelView);

    verticalLayout->addWidget(scrollArea);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    sliderScale = new QSlider(this);
    sliderScale->setObjectName(QString::fromUtf8("sliderScale"));
    sliderScale->setMinimum(1);
    sliderScale->setMaximum(800);
    sliderScale->setValue(100);
    sliderScale->setOrientation(Qt::Horizontal);

    horizontalLayout->addWidget(sliderScale);

    buttonOriginalSize = new QToolButton(this);
    buttonOriginalSize->setObjectName(QString::fromUtf8("buttonOriginalSize"));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/icons/view"), QSize(), QIcon::Normal, QIcon::Off);
    buttonOriginalSize->setIcon(icon1);

    horizontalLayout->addWidget(buttonOriginalSize);

    buttonFitToWindow = new QToolButton(this);
    buttonFitToWindow->setObjectName(QString::fromUtf8("buttonFitToWindow"));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/icons/monitor_link"), QSize(), QIcon::Normal, QIcon::Off);
    buttonFitToWindow->setIcon(icon2);
    buttonFitToWindow->setCheckable(true);

    horizontalLayout->addWidget(buttonFitToWindow);

    verticalLayout->addLayout(horizontalLayout);

    //retranslateUi(this);
    QObject::connect(actionPrintImage, SIGNAL(triggered()), this, SLOT(openPrintImageDialog()));
    QObject::connect(sliderScale, SIGNAL(valueChanged(int)), this, SLOT(scaleImage(int)));
    QObject::connect(buttonFitToWindow, SIGNAL(toggled(bool)), this, SLOT(scaleToFitWindow(bool)));

    QMetaObject::connectSlotsByName(this);
}
