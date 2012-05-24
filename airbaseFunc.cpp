#include "mainwindow.h"
#include "FunctionList.h"

void MainWindow::airbaseFunc()
{
	static bool st = false;
	QProcess *airbase0 = new QProcess();
	QProcess *airbase1 = new QProcess();
        QProcess *killAirbase = new QProcess();
        QString airbase_addr0 = APP_CURRENT_PATH.append("/airbaseKill.sh").append(" ").append(ui->essidBox->text());
        QString airbase_addr1 = APP_CURRENT_PATH.append("/airbase-sh1.sh").append(" ").append(ui->essidBox->text());
        QString airbase_addr2 = APP_CURRENT_PATH.append("/airbase-sh2.sh").append(" ").append(ui->essidBox->text());
	if(st)
	{
		ui->airbaseBtn->setText("Turn On");
                ui->btn1->setDisabled(true);
		ui->essidBox->setEnabled(true);
                ui->airmonBtn->setEnabled(true);
		st = false;

                killAirbase->start(airbase_addr0);
	}
	else
	{
		ui->airbaseBtn->setText("Turn Off");
                ui->btn1->setEnabled(true);
		ui->essidBox->setDisabled(true);
                ui->airmonBtn->setDisabled(true);
		st = true;

		airbase0->start(airbase_addr1);
		sleep(3);
		airbase1->start(airbase_addr2);
	}
}
