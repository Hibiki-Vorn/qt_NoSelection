#ifndef MAIN_H
#define MAIN_H

#include <QObject>
#include <QVariant>
#include <QMessageBox>
#include <QApplication>
#include <QRandomGenerator>

class WindowAction : public QObject {
    Q_OBJECT

public:
    explicit WindowAction(QObject* parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void bindButtons(QObject* button_yes, QObject* button_no) {
        this->button_yes = button_yes;
        this->button_no = button_no;
    }

    Q_INVOKABLE void onMouseMovedOnButtonNo() {
        if (!button_no) return;

        qreal maxX = 640 - 100;
        qreal maxY = 480 - 80;

        qreal newX = QRandomGenerator::global()->bounded(maxX);
        qreal newY = QRandomGenerator::global()->bounded(maxY);

        button_no->setProperty("x", newX);
        button_no->setProperty("y", newY);
    }

    Q_INVOKABLE void dialog_no() {
        QMessageBox msgBox;
        msgBox.setText("You are idiot!");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStandardButtons(QMessageBox::Close);

        int ret = msgBox.exec();
        if(ret == QMessageBox::Close) QCoreApplication::quit();
    }

private:
    QObject* button_yes = nullptr;
    QObject* button_no = nullptr;
};

#endif // MAIN_H
