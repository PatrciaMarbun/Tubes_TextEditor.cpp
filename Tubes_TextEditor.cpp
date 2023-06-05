/* Jelly Ulita Tamsar (221402010)
Patricia Marbun (221402026)
Damai C C Hutauruk (221402092)
Elisabet Sri Hartati (221402095)*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TextEditor
{
private:
    void showWelcomeMessage();
    void showMainMenu();
    int getChoice();
    string getFilename();
    string getInputText();
    void createNewFile();
    void addTextToFile();
    void readFile();
    void clearFile();
    void deleteFile();
    void copyFile();
    void compileFile();
    void runFile();
    void exitProgram();

public:
    void start();
};

void TextEditor::showWelcomeMessage()
{
    system("cls");
    cout << "~~~~~~~~" << endl;
    cout << "WELCOME TO TEXT EDITOR" << endl;
    cout << "~~~~~~~~" << endl;
}

void TextEditor::showMainMenu()
{
    cout << "-------------" << endl;
    cout << "  Main Menu " << endl;
    cout << "-------------" << endl;
    cout << "1. Buat File Baru" << endl;
    cout << "2. Tambah teks ke File" << endl;
    cout << "3. Baca File" << endl;
    cout << "4. Kosongkan File" << endl;
    cout << "5. Hapus File" << endl;
    cout << "6. Copy File" << endl;
    cout << "7. Kompilasi File" << endl;
    cout << "8. Run File" << endl;
    cout << "9. Exit" << endl
         << endl;
    cout << "Masukkan Pilihan: ";
}

int TextEditor::getChoice()
{
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}

string TextEditor::getFilename()
{
    string filename;
    cout << endl
         << "Masukkan Nama File: ";
    getline(cin, filename);
    return filename;
}

string TextEditor::getInputText()
{
    string text;
    string line;
    cout << endl
         << "Tulis teks yang ingin dimasukkan ke file : (Ketik END untuk mengakhiri)" << endl;
    while (getline(cin, line))
    {
        if (line == "END")
        {
            break;
        }
        else
        {
            text += line + "\n";
        }
    }
    return text;
}

void TextEditor::createNewFile()
{
    string filename = getFilename();
    ofstream myfile(filename.c_str());
    myfile.close();
    cout << "File Sukses Dibuat!" << endl
         << endl;

    string text = getInputText(); // Prompt for input after file creation
    ofstream appendFile(filename.c_str(), ios::app);
    appendFile << text;
    appendFile.close();
    cout << "Teks berhasil ditambahkan ke file!" << endl
         << endl;
    cout << endl
         << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::addTextToFile()
{
    string filename = getFilename();
    string text = getInputText();
    ofstream myfile(filename.c_str(), ios::app);
    myfile << text;
    myfile.close();
    cout << "File Sukses Di Update!" << endl
         << endl;
    cout << endl
         << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::readFile()
{
    string filename = getFilename();
    ifstream myfile(filename.c_str());
    if (!myfile)
    {
        cout << "File Tidak Ditemukan!" << endl
             << endl;
    }
    else
    {
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    cout << endl
         << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::clearFile()
{
    string filename = getFilename();
    ofstream myfile(filename.c_str());
    myfile << "";
    myfile.close();
    cout << "File berhasil dikosongkan!" << endl
         << endl;
    cin.ignore();
    cin.get();
}

void TextEditor::deleteFile()
{
    string filename = getFilename();
    if (remove(filename.c_str()) == 0)
    {
        cout << "File berhasil dihapus!" << endl
             << endl;
    }
    else
    {
        cout << "File Tidak Ditemukan!" << endl
             << endl;
    }
    cout << endl
         << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::copyFile()
{
    string sourceFilename, destinationFilename;
    cout << endl
         << "Masukkan Nama File Yang ingin Di Copy: ";
    getline(cin, sourceFilename);
    ifstream sourceFile(sourceFilename.c_str());
    if (!sourceFile)
    {
        cout << "File Tidak Ditemukan!" << endl
             << endl;
        cout << endl
             << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    }
    string line, text;
    while (getline(sourceFile, line))
    {
        text += line + "\n";
    }
    sourceFile.close();
    cout << endl
         << "Masukkan Nama file baru dari file yg di Copy: ";
    getline(cin, destinationFilename);
    ofstream destinationFile(destinationFilename.c_str(), ios::app);
    destinationFile << text;
    destinationFile.close();
    cout << "File berhasil dicopy!" << endl
         << endl;
    cout << endl
         << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::compileFile()
{
    string filename = getFilename();
    string command = "g++ " + filename + ".cpp -o " + filename;
    int result = system(command.c_str());
    if (result == 0)
    {
        cout << "\n~~~~~~~~~~" << endl;
        cout << " File berhasil dikompilasi!" << endl;
        cout << "~~~~~~~~~~" << endl;
    }
    else
    {
        cout << "Terjadi kesalahan saat melakukan kompilasi file." << endl
             << endl;
    }
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::runFile()
{
    string filename = getFilename();
    string command = filename + ".exe";
    cout << endl
         << "Output dari file yang dijalankan:" << endl
         << endl;
    system(command.c_str());
    cout << endl
         << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void TextEditor::exitProgram()
{
    exit(EXIT_SUCCESS);
}

void TextEditor::start()
{
    showWelcomeMessage();
    while (true)
    {
        showMainMenu();
        int choice = getChoice();

        switch (choice)
        {
        case 1:
            createNewFile();
            break;
        case 2:
            addTextToFile();
            break;
        case 3:
            readFile();
            break;
        case 4:
            clearFile();
            break;
        case 5:
            deleteFile();
            break;
        case 6:
            copyFile();
            break;
        case 7:
            compileFile();
            break;
        case 8:
            runFile();
            break;
        case 9:
            exitProgram();
            break;
        default:
            cout << "\n~~~~~~~~~~~~" << endl;
            cout << " Pilihan Tidak Valid, Coba Lagi!" << endl;
            cout << "~~~~~~~~~~~~" << endl;
            break;
        }
    }
}

int main()
{
    TextEditor textEditor;
    textEditor.start();
    return 0;
}