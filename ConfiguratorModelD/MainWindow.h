/*!
 * \file MainWindow.h
 * \author masc4ii
 * \copyright 2018
 * \brief The main window
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmidiout.h"
#include "qmidimapper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSendAll_triggered();
    void on_comboBoxKeyPrio_activated(int index);
    void on_spinBoxMidiChannel_editingFinished();

    void on_comboBoxMultiTrigger_activated(int index);

    void on_spinBoxPitchBend_editingFinished();

    void on_spinBoxTranspose_editingFinished();

    void on_comboBoxModCurve_activated(int index);

    void on_actionAboutQt_triggered();

    void on_actionAboutConfiguratorModelD_triggered();

private:
    Ui::MainWindow *ui;
    void getPorts(void);
    void searchModelD(void);
    std::vector<unsigned char> buildMessage( unsigned char parNr, unsigned char value );

    QMidiOut *m_midiOut;
};

#endif // MAINWINDOW_H
