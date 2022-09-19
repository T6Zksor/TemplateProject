#include "mainwindow.h"

#include <QApplication>
#include <QTimer>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

#include <memory>
#include <concepts>
#include <string>
//#include <ranges>

#include "Poco/ActiveDispatcher.h"
#include "Poco/ActiveMethod.h"
#include "Poco/FunctionDelegate.h"

#include "fmt/format.h"


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
