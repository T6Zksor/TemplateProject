#include "mainwindow.h"

#include <QListWidget>
#include <QPushButton>
#include <QRandomGenerator>
#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>

MyFrame::MyFrame(QWidget* parent /*= nullptr*/) {
    // setStyleSheet("background-color:rgba(0,0,0,0.5);");
    auto rootLayout = new QHBoxLayout{this};
    rootLayout->setContentsMargins({});

    auto lb1 = new QLabel{"lb1"};
    auto lb2 = new QLabel{"lb2"};
    auto btn1 = new QPushButton{"btn1"};
    rootLayout->addWidget(lb1);
    rootLayout->addWidget(lb2);
    rootLayout->addWidget(btn1);

    setMinimumHeight(QRandomGenerator::global()->bounded(25, 150));
}

QSize MyFrame::sizeHint() const {
    auto sz = __super::sizeHint();
    return sz;
}

class MyLbl : public QLabel {
public:
    QSize sizeHint() const override {
        return __super::sizeHint();
    }

};

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) { setupUi(); }

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    setMinimumSize(800, 600);
    auto rootLayout = new QVBoxLayout{this};

    auto lyt1 = new QVBoxLayout{};
    auto lyt2 = new QVBoxLayout{};

    rootLayout->addLayout(lyt1);
    rootLayout->addLayout(lyt2);

    auto lbl = new MyLbl{};
    lbl->setText("text1");
    lbl->setStyleSheet("background-color:yellow;");
    lbl->setFixedHeight(50);
    lyt1->addWidget(lbl);
    lyt1->setSizeConstraint(QLayout::SetFixedSize);

    auto lbl2 = new QLabel{"text2"};
    lbl2->setStyleSheet("background-color:green;");
    lbl2->setFixedHeight(50);
    lyt2->addWidget(lbl2);

    //rootLayout->addSpacing(200);
}
