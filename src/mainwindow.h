#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

   private:
    void setupUi();

   private:
    QAction* actionPrintImage;
    QVBoxLayout* verticalLayout;
    QScrollArea* scrollArea;
    QLabel* labelView;
    QHBoxLayout* horizontalLayout;
    QSpacerItem* horizontalSpacer;
    QSlider* sliderScale;
    QToolButton* buttonOriginalSize;
    QToolButton* buttonFitToWindow;
};

#endif  // MAINWINDOW_H
