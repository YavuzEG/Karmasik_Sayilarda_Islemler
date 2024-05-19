
//Gerekli kütüphaneleri ekledim.
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;
//pi nin değişmez değerini tanımladım.
const double pi = 3.14159265;

//karmaşık sayı classını oluşturdum
class Karmasik_sayi {
public:
    //gerçek kısmı ve reel kısmı tanımladım.
    double gercek;
    double sanal;

    //Kutupsal Gösterimde ihtiyacım olanları tanımladım.
    double radyan;
    double derece;

    //'+' operatörünü aşırı yükledim
    Karmasik_sayi operator +(Karmasik_sayi sayi)
    {
        Karmasik_sayi yeni_sayi;
        yeni_sayi.gercek = gercek + sayi.gercek;
        yeni_sayi.sanal = sanal + sayi.sanal;
        return yeni_sayi;
    }

    //'-' operatörünü aşırı yükledim
    Karmasik_sayi operator -(Karmasik_sayi sayi)
    {
        Karmasik_sayi yeni_sayi;
        yeni_sayi.gercek = gercek - sayi.gercek;
        yeni_sayi.sanal = sanal - sayi.sanal;
        return yeni_sayi;
    }

    // '*' operatörünü aşırı yükledim
    Karmasik_sayi operator *(Karmasik_sayi sayi)
    {
        Karmasik_sayi yeni_sayi;
        yeni_sayi.gercek = gercek * sayi.gercek - sanal * sayi.sanal;
        yeni_sayi.sanal = gercek * sayi.sanal + sayi.gercek * sanal;
        return yeni_sayi;
    }

    // '/' operatörünü aşırı yükledim
    Karmasik_sayi operator /(Karmasik_sayi sayi)
    {
        Karmasik_sayi yeni_sayi;
        yeni_sayi.gercek = (gercek * sayi.gercek + sanal * sayi.sanal) / (pow(sayi.gercek, 2) + pow(sayi.sanal, 2));
        yeni_sayi.sanal = (sayi.gercek * sanal - gercek * sayi.sanal) / (pow(sayi.gercek, 2) + pow(sayi.sanal, 2));
        return yeni_sayi;
    }

    // '+=' operatörünü aşırı yükledim
    Karmasik_sayi operator +=(Karmasik_sayi& sayi)
    {
        this->gercek = (this->gercek + sayi.gercek);
        this->sanal = (this->sanal + sayi.sanal);
        return *this;
    }

    // '-=' operatörünü aşırı yükledim
    Karmasik_sayi operator -=(Karmasik_sayi& sayi)
    {
        this->gercek = (this->gercek - sayi.gercek);
        this->sanal = (this->sanal - sayi.sanal);
        return *this;
    }

    // '*=' operatörünü aşırı yükledim
    Karmasik_sayi operator *=(Karmasik_sayi& sayi)
    {
        this->gercek = (this->gercek * sayi.gercek) - (this->sanal * sayi.sanal);
        this->sanal = (this->gercek * sayi.sanal) + (sayi.gercek * this->sanal);
        return *this;
    }

    // '/=' operatörünü aşırı yükledim
    Karmasik_sayi operator /=(Karmasik_sayi& sayi)
    {
        this->gercek = ((this->gercek * sayi.gercek) + (this->sanal * sayi.sanal)) / (pow(sayi.gercek, 2) + pow(sayi.sanal, 2));
        this->sanal = ((sayi.gercek * this->sanal) - (this->gercek * sayi.sanal)) / (pow(sayi.gercek, 2) + pow(sayi.sanal, 2));
        return *this;
    }

    //Karmaşık sayının girilmesi için fonkisyon oluşturdum.
    void girdi() {
        cout << "\tSayının gerçek kısmını giriniz:";
        cin >> gercek;

        //Girilen değerin sayı olup olmadığına bakan, sayı değil ise sayı girene kadar tekrar değer girdiren döngü yazdım.
        while (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t!!SAYI GİRMEİZ LAZIM!!\n" << endl;
            cout << "\tSayının gerçek kısmını giriniz";
            cin >> gercek;
        }

        cout << "\tSayının sanal kısmının katsayısınıı giriniz:";
        cin >> sanal;
        while (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t!!SAYI GİRMEİZ LAZIM!!\n" << endl;
            cout << "\tSayının sanal kısmının katsayısınıı giriniz:";
            cin >> sanal;
        }
    }

    //Karmaşık sayıyı ekrana yazdıran fonksiyonu yazdım.
    void cikti(string yazı)
    {
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        if (sanal > 0 && gercek != 0)
            cout << "\t" << yazı << gercek << "+" << sanal << "i" << endl;
        else if (sanal < 0 && gercek != 0)
            cout << "\t" << yazı << gercek << sanal << "i" << endl;
        else if (sanal > 0 && gercek == 0)
            cout << "\t" << yazı << sanal << "i" << endl;
        else if (sanal < 0 && gercek == 0)
            cout << "\t" << yazı << sanal << "i" << endl;
        else
            cout << "\t" << yazı << gercek << endl;
    }
};


int main()
{
    //Türkçe karakterleri algılasın diye ekledim.
    setlocale(LC_ALL, "Turkish");

    //Yeniden işlem yapma ve işemi durdurmada gerekli olan charları tanımladım.
    char yeni;
    char dur;

    //Yeniden işlem yapabilelim diye hesap makinesini do while döngüsüne aldım.
    do {
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\tKARMAŞIK SAYILARDA HESAP MAKİNESİ" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t[1] TOPLAMA İŞLEMİ" << endl;//Hangi işlemi yapmak istersin diye sordum.
        cout << "\t[2] ÇIKARMA İŞLEMİ" << endl;
        cout << "\t[3] ÇARPMA İŞLEMİ" << endl;
        cout << "\t[4] BÖLME İŞLEMİ" << endl;
        cout << "\t[5] ÇOKLU TOPLAMA İŞLEMİ" << endl;
        cout << "\t[6] ÇOKLU ÇIKARMA İŞLEMİ" << endl;
        cout << "\t[7] ÇOKLU ÇARPMA İŞLEMİ" << endl;
        cout << "\t[8] ÇOKLU BÖLME İŞLEMİ" << endl;
        cout << "\t[9] KUTUPSAL GÖSTERİM" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\tYapmak istediğiniz işleme atanmış numarayı tuşlayınız:";//yapmak istediği işlemi atanmış tuşu tuşlamasını istedim.
        char tus;
        cin >> tus;

        //işlem yaparken gireceği karmaşık sayıları classla tanımladım.
        Karmasik_sayi sayi1, sayi2;

        //İşleme başlarken ekrandaki her şeyi sildim.
        system("CLS");

        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

        //Seçeceği tuşa göre işlem yapılsın diye switch case kullandım.
        switch (tus) {
        case '1':
            cout << "\tTOPLAMA İŞLEMİ" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();//fonksiyonla 1. sayıyı girdirdim
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");//fonksiyonla 1. sayıyı ekrana yazdırdım.
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi2.girdi();//fonksiyonla 2. sayıyı girdirdim
            sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");//fonksiyonla 2. sayıyı ekrana yazdırdım.
            Karmasik_sayi sayi3 = sayi1 + sayi2;//İkisinin işleminin sonucunu 
            sayi3.cikti("Sonuç:");//Sonucu fonksiyonla ekrana yazdırdım.
            break;//switch case den çıktım.

        case '2':
            cout << "\tÇIKARMA İŞELMİ" << endl;//Toplama ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi2.girdi();
            sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
            Karmasik_sayi sayi4 = sayi1 - sayi2;
            sayi4.cikti("Sonuç:");
            break;

        case '3':
            cout << "\tÇARPMA İŞELMİ" << endl;//Toplama ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi2.girdi();
            sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
            Karmasik_sayi sayi5 = sayi1 * sayi2;
            sayi5.cikti("Sonuç:");
            break;

        case '4':
            cout << "\tBÖLME İŞELMİ" << endl;//Toplama ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi2.girdi();
            sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
            Karmasik_sayi sayi6 = sayi1 / sayi2;
            sayi6.cikti("Sonuç:");
            break;

        case '5':
            cout << "\tÇoklu Toplama" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();//fonksiyonla 1. sayıyı girdirdim
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");//fonksiyonla 1. sayıyı ekrana yazdırdım.
            do {
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi2.girdi();//fonksiyonla diğer sayıyı girdirdim
                sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");//fonksiyonla diğer sayıyı ekrana yazdırdım.
                sayi1 += sayi2;//diğer sayıyı 1. sayıya ekledim
                sayi1.cikti("Sonuç:");//sonucu fonksiyonla ekrana yazdırdım.
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "İşlemi durdurmak istiyorsanız [D] tuşlayın.Karmaşık sayı eklemek istiyorsanız herhangi bir tuşa basın" << endl;//başka bir sayı eklemek isteyip istemediğini sorudum.
                //isterse sayi2 yeni bir değer girilicek ve sayi1 in üstüne eklenicek bu şekilde 3 farklı karmaşık sayı toplanmış olucak.
                cin >> dur;
            } while (dur == 'd' || dur == 'D');//d girene kadar do while devam edicek.
            sayi1.cikti("Sonuç:");//d girerse en son sayi1 değerini ekrana yazdırıcak.
            break;

        case '6':
            cout << "\tÇOKLU ÇIKARMA" << endl;//+= ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            do {
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi2.girdi();
                sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
                sayi1 -= sayi2;
                sayi1.cikti("Sonuç:");
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "İşlemi durdurmak istiyorsanız [D] tuşlayın.Karmaşık sayı eklemek istiyorsanız herhangi bir tuşa basın" << endl;
                cin >> dur;
            } while (dur == 'd' || dur == 'D');
            sayi1.cikti("Sonuç:");
            break;

        case '7':
            cout << "\tÇOKLU ÇARPMA" << endl;//+= ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            do {
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi2.girdi();
                sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
                sayi1 *= sayi2;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi1.cikti("Sonuç:");
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "İşlemi durdurmak istiyorsanız [D] tuşlayın.Karmaşık sayı eklemek istiyorsanız herhangi bir tuşa basın" << endl;
                cin >> dur;
            } while (dur == 'd' || dur == 'D');
            sayi1.cikti("Sonuç:");
            break;

        case '8':
            cout << "\tÇOKLU BÖLME" << endl;//+= ile aynı mantık
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");
            do {
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi2.girdi();
                sayi2.cikti("Girmiş olduğunuz karmaşık sayı:");
                sayi1 /= sayi2;
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                sayi1.cikti("Sonuç:");
                cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "İşlemi durdurmak istiyorsanız [D] tuşlayın.Karmaşık sayı eklemek istiyorsanız herhangi bir tuşa basın" << endl;
                cin >> dur;
            } while (dur == 'd' || dur == 'D');
            sayi1.cikti("Sonuç:");
            break;

        case '9':
            cout << "\tKUTUPSAL GÖSTERİM" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            sayi1.girdi();//1 sayı girmesini istedim.
            sayi1.cikti("Girmiş olduğunuz karmaşık sayı:");//sayıyı ekrana yazdırdım.
            Karmasik_sayi hipo;//hipotenüs classla tanımladım.
            hipo.gercek = sqrt(pow(sayi1.gercek, 2) + pow(sayi1.sanal, 2));//hipotenüsü buldum.
            sayi1.gercek = sayi1.gercek / hipo.gercek;//gerçek kısmın açısının cos değerini hesaplattım.
            //cos u açıya çeviirdim ve aynı işlemi sanal kısma uyguladım.
            sayi1.radyan = acos(sayi1.gercek);
            sayi1.derece = sayi1.radyan * 180.0 / pi;
            sayi1.sanal = sayi1.sanal / hipo.gercek;
            sayi2.radyan = acos(sayi1.sanal);
            sayi2.derece = sayi2.radyan * 180.0 / pi;
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\tSonuç:" << hipo.gercek << "(" << sayi1.derece << "+" << sayi2.derece << "i" << ")" << endl;//sonucu ekrana yazdırdım.
            break;

        default:
            cout << "!!\nSEÇENEK BULUNAMADI!!";
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\tYeni bir işlem yapmak istiyorsanız [Y] tuşuna tıklayınız." << endl;//Tekrar işlem yapmak işteyip istemediğpini sordum.
        cin >> yeni;

        system("CLS");//ekrandaki her şeyi sildirdim

    } while (yeni == 'Y' || yeni == 'y');//Eğer y girerse tekrar işlem seçme ekranı gelicek, girmezse program biticek.

    return 0;
}

