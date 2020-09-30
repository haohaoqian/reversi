#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void mainmenu_1();
    void mainmenu_2();
    void mainmenu_3();
    void mainmenu_4();
    void mainmenu_5();
    void doublemenu_1();
    void doublemenu_2();
    void singlemenu_1();
    void singlemenu_2();
    void singlemenu_3();
    void settingmenu_1();
    void settingmenu_2();
    void settingmenu_3();
    void programmermenu();
    void singlemenu_2_1();
    void singlemenu_2_2();
    void singlemenu_2_1_1();
    void singlemenu_2_1_2();
    void play_black_double();
    void play_white_double();
    void play_black_single();
    void play_white_single();
    void escape();
    void escape_1();
    void escape_2();
    void click00();
    void click01();
    void click02();
    void click03();
    void click04();
    void click05();
    void click06();
    void click07();
    void click10();
    void click11();
    void click12();
    void click13();
    void click14();
    void click15();
    void click16();
    void click17();
    void click20();
    void click21();
    void click22();
    void click23();
    void click24();
    void click25();
    void click26();
    void click27();
    void click30();
    void click31();
    void click32();
    void click35();
    void click36();
    void click37();
    void click40();
    void click41();
    void click42();
    void click45();
    void click46();
    void click47();
    void click50();
    void click51();
    void click52();
    void click53();
    void click54();
    void click55();
    void click56();
    void click57();
    void click60();
    void click61();
    void click62();
    void click63();
    void click64();
    void click65();
    void click66();
    void click67();
    void click70();
    void click71();
    void click72();
    void click73();
    void click74();
    void click75();
    void click76();
    void click77();
    void save();
    void nosave();
public:
    void clear_window();
    void reset_window();
    void prepare();
    void print_chessboard();
    void print_chessboard(ofstream &p);
    void clear_chessboard();
    void input_position();
    void player(bool m);
    void player_(bool m);
    void player_end(bool m);
    void save_choice();
};

#endif // MAINWINDOW_H
