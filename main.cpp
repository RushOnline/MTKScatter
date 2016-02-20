#include <QApplication>

#include "mainwindow.h"
#include "mtkscatter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MTKScatter scatter;
    Q_ASSERT(scatter.loadFromFile("/home/rush/opt/Hammer/MP_mt6732_m316b_blueplus_nyx_cc_128-16_kk_lte_3m-fdd-cs_mul_sw_20150530-133115_songlixin_PC/MT6752_Android_scatter.txt"));

//    return 0;
    return a.exec();
}
