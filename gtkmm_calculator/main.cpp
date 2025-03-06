#include <gtkmm.h>

class CalculatorWindow : public Gtk::Window {
public:
    CalculatorWindow() {
        set_title("Simple Calculator");
        set_default_size(600, 400);

        // Create a box to arrange the buttons and display vertically
        box.set_orientation(Gtk::ORIENTATION_HORIZONTAL);

        // Add display
        box.pack_start(display, Gtk::PACK_SHRINK);

        // Buttons
        button0.set_label("0");
        button1.set_label("1");
        button2.set_label("2");
        button3.set_label("3");
        button4.set_label("4");
        button5.set_label("5");
        button6.set_label("6");
        button7.set_label("7");
        button8.set_label("8");
        button9.set_label("9");

        buttonAdd.set_label("+");
        buttonEquals.set_label("=");

        // Connect signals to methods
        button0.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button0_clicked));
        button1.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button1_clicked));
        button2.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button2_clicked));
        button3.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button3_clicked));
        button4.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button4_clicked));
        button5.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button5_clicked));
        button6.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button6_clicked));
        button7.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button7_clicked));
        button8.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button8_clicked));
        button9.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_button9_clicked));
        buttonAdd.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_buttonAdd_clicked));
        buttonEquals.signal_clicked().connect(sigc::mem_fun(*this, &CalculatorWindow::on_buttonEquals_clicked));

        // Pack buttons
        Gtk::Box* buttonBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
        buttonBox->pack_start(button0);
        buttonBox->pack_start(button1);
        buttonBox->pack_start(button2);
        buttonBox->pack_start(button3);
        buttonBox->pack_start(button4);
        buttonBox->pack_start(button5);
        buttonBox->pack_start(button6);
        buttonBox->pack_start(button7);
        buttonBox->pack_start(button8);
        buttonBox->pack_start(button9);
        
        buttonBox->pack_start(buttonAdd);
        buttonBox->pack_start(buttonEquals);
        
        box.pack_start(*buttonBox);

        // Add the box to the window
        add(box);
        show_all_children();
    }

protected:
    // Button click handlers
    void on_button0_clicked(){
        display.set_text(display.get_text() + "0");
    }
    void on_button1_clicked() {
        display.set_text(display.get_text() + "1");
    }

    void on_button2_clicked() {
        display.set_text(display.get_text() + "2");
    }
    void on_button3_clicked(){
        display.set_text(display.get_text() + "3");
    }
    void on_button4_clicked() {
        display.set_text(display.get_text() + "4");
    }

    void on_button5_clicked() {
        display.set_text(display.get_text() + "5");
    }
    void on_button6_clicked(){
        display.set_text(display.get_text() + "6");
    }
    void on_button7_clicked() {
        display.set_text(display.get_text() + "7");
    }

    void on_button8_clicked() {
        display.set_text(display.get_text() + "8");
    }
    
    void on_button9_clicked() {
        display.set_text(display.get_text() + "9");
    }

    void on_buttonAdd_clicked() {
        display.set_text(display.get_text() + "+");
    }
    
    void on_buttonEquals_clicked() {
        // For simplicity, let's just print the text (no calculation logic yet)
        std::string result = display.get_text();
        display.set_text("Result: " + result);
    }

private:
    Gtk::Box box;
    Gtk::Entry display;
    Gtk::Button button0, button1, button2, button3,button4, button5, button6, button7, button8, button9, buttonAdd, buttonEquals;
};

int main(int argc, char* argv[]) {
    Gtk::Main kit(argc, argv);

    CalculatorWindow window;
    Gtk::Main::run(window);

    return 0;
}