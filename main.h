#ifndef MAIN_H
#define MAIN_H

#include <QObject>
#include <QWindow>
#include <QVariant>
#include <QMessageBox>
#include <QApplication>
#include <QRandomGenerator>

class WindowAction : public QObject {
    Q_OBJECT

    public:
        explicit WindowAction(QObject* parent = nullptr) : QObject(parent) {}

        Q_INVOKABLE void bind(QWindow* mainWindow, QObject* button_yes, QObject* button_no) {
            this->mainWindow = mainWindow;
            this->button_yes = button_yes;
            this->button_no = button_no;

            mainWindow->setIcon(QPixmap(":/favicon.png"));
        }

        Q_INVOKABLE void onMouseMovedOnButtonNo() {
            if (!button_no) return;

            qreal maxX = 640 - 120;
            qreal maxY = 480 - 100;

            qreal newX = QRandomGenerator::global()->bounded(maxX);
            qreal newY = QRandomGenerator::global()->bounded(maxY);

            button_no->setProperty("x", newX);
            button_no->setProperty("y", newY);
        }

        Q_INVOKABLE void dialog_yes() {
            QMessageBox msgBox;
            msgBox.setWindowTitle(" ");
            msgBox.setText("You are really idiot!");
            msgBox.setIconPixmap(QPixmap(":/icon.png").scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            msgBox.setStandardButtons(QMessageBox::Close);

            int ret = msgBox.exec();
            if(ret == QMessageBox::Close) QCoreApplication::quit();
        }

        Q_INVOKABLE void dialog_no() {
            QMessageBox msgBox;
            msgBox.setWindowTitle(" ");
            msgBox.setText("You are so clever!");
            msgBox.setIconPixmap(QPixmap(":/favicon.png").scaled(64, 64, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            msgBox.setStandardButtons(QMessageBox::Close);

            int ret = msgBox.exec();
            if(ret == QMessageBox::Close) QCoreApplication::quit();
        }

    private:
        QWindow* mainWindow = nullptr;
        QObject* button_yes = nullptr;
        QObject* button_no = nullptr;
};

#endif // MAIN_H
