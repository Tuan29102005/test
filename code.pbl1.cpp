#include <iostream>
#include<string>
using namespace std;

class sach {
private:
    string tuade;
    string tacgia, ISBN, theloai, vitriluutru;
    int soluongcosan;
   
public:
    sach(string td = "", string tg = "", string I = "", string tl = "", int slcs = 0, string vitri = "") :tuade(td), tacgia(tg), ISBN(I), theloai(tl), vitriluutru(vitri), soluongcosan(slcs) {}
        string gettuade() const { return tuade; }
        string gettacgia() const { return tacgia; }
        string getISBN() const { return ISBN; }
        string gettheloai() const { return theloai; }
        string getvitriluutru() const { return vitriluutru; }
        int getsoluongcosan() const { return soluongcosan; }
        void setsoluongcosan(int soluong) { soluongcosan = soluong; }
        void hienthithongtin() const {
            cout << " tua de : " <<tuade << "tac gia" << tacgia << "ISBN" << ISBN << "the loai" <<
                theloai << "so luong san co" << soluongcosan << "vi tri luu tru" << vitriluutru << endl;

        }
        void nhapthongtin() {
            cout << "nhap tua de " << endl; getline(cin, tuade);
            cout << "nhap ten tac gia" << endl; getline(cin, tacgia);
            cout << "nhap ISBN " << endl; getline(cin, ISBN);
            cout << "nhap the loai" << endl; getline(cin, theloai);
            cout << "nhap so luong co san " << endl; cin >> soluongcosan;
            cin.ignore();
            cout << "nhap vi tri luu tru" << endl; getline(cin, vitriluutru);
        }

};
class nguoidung {
private:
    int idnguoidung;
    string ten, email, sodienthoai;
public:
    nguoidung(int i = 0, string Ten = "", string Email = "", string Sodienthoai = "")
        :idnguoidung(i), ten(Ten), email(Email), sodienthoai(Sodienthoai) {}
    int getidnguoidung() const { return idnguoidung; }
    string getten() const { return ten; }
    string getemail() const { return email; }
    string getsodienthoai() const { return sodienthoai; }
    void hienthithongtinnguoidung() const {
        cout << "id nguoi dung" << idnguoidung << "ten nguoi dung" << ten << "email nguoi dung" << email << "so dien thoai nguoi dung"
            << sodienthoai << endl;
    }
    void nhapthongtinnguoidung() {
        cout << "nhap id nguoi dung" << endl; cin >> idnguoidung;
        cin.ignore();
        cout << "nhap ten nguoi dung" << endl; getline(cin, ten);
        cout << "nhap email nguoi dung" << endl; getline(cin, email);
        cout << "nhap so dien thoai nguoi dung" << endl; getline(cin, sodienthoai);
    }
};
class thuvien {
private:
    sach* danhsachsach;
    int soluongsach;
    nguoidung* danhsachnguoidung;
    int soluongnguoidung;
public:
    thuvien() :danhsachsach(0), soluongsach(0), danhsachnguoidung(0), soluongnguoidung(0) {}
    ~thuvien() {
        delete[] danhsachsach;
        delete[] danhsachnguoidung;
    }
    void themsach() {
        sach Sach;
        Sach.nhapthongtin();
        sach* temp = new sach[soluongsach + 1];
        for (int i = 0; i < soluongsach; i++) {
            temp[i] = danhsachsach[i];

        }
        temp[soluongsach] = Sach;
        delete[]danhsachsach;
        danhsachsach = temp;
        soluongsach++;

    }
    void xoasach(const string& ISBN) {
        int index = -1;
        for (int i = 0; i < soluongsach; i++) {
            if (danhsachsach[i].getISBN() == ISBN) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "khong tim thay sach voi ISBN" << endl;
            return;
        }
        sach* temp = new sach[soluongsach - 1];
        for (int i = 0, j = 0; i < soluongsach; ++i) {
            if (i != index) {
                temp[j++] = danhsachsach[i];
            }
        }
        delete[] danhsachsach;
        danhsachsach = temp;
        soluongsach--;
        cout << "sach da xoa " << ISBN << endl;

    }
    sach* timsach(const string& ISBN) {
        for (int i = 0; i < soluongsach; i++) {
            if (danhsachsach[i].getISBN() == ISBN) {
                return &danhsachsach[i];
            }
        }
        return 0;

    }
    void themnguoidung() {
        nguoidung Nguoidung;
        Nguoidung.nhapthongtinnguoidung();
        nguoidung* temp = new nguoidung[soluongnguoidung + 1];
        for(int i = 0; i < soluongnguoidung; i++){
            temp[i] = danhsachnguoidung[i];
         }
        temp[soluongnguoidung] = Nguoidung;
            delete[] danhsachnguoidung;
            danhsachnguoidung = temp;
            soluongnguoidung++;
        }
        void xoanguoidung(int id) {
            int index = -1;
            for (int i = 0; i < soluongnguoidung; i++) {
                if (danhsachnguoidung[i].getidnguoidung() == id) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                cout << "khong tim thay thong tin nguoi dung voi ID" << endl;
                return;
               }
            nguoidung* temp = new nguoidung[soluongnguoidung - 1];
            for (int i = 0,j=0; i < soluongnguoidung; i++) {
                if (i != index) {
                    temp[j++] = danhsachnguoidung[i];
                        
                }
            }
            delete danhsachnguoidung;
            danhsachnguoidung = temp; soluongnguoidung--;
            cout << "da xoa nguoi dung voi id" << id << endl;
        }
        void chomuonsach(const string& ISBN) {
            sach* Sach = timsach(ISBN);
            if (Sach != 0) {
                Sach->setsoluongcosan(Sach->getsoluongcosan() + 1);
                cout << "da tra sach voi ISBN" << ISBN << endl;
            }
            else {
                cout << "khong tim thay sach voi ISBN" << ISBN << endl;

            }
        }
        void trasach(const string& ISBN) {
            sach* Sach = timsach(ISBN);
            if (Sach != 0) {
                Sach->setsoluongcosan(Sach->getsoluongcosan() + 1);
                cout << "da tra sach voi ISBN" << ISBN << endl;

            }
            else {
                cout << "khong tim thay sach voi ISBN" << ISBN << endl;

            }
        }
        void hienthisach()const {
            for (int i = 0; i < soluongsach; i++) {
                danhsachsach[i].hienthithongtin();
                cout << endl;

            }
        }
        void hienthinguoidung()const {
            for (int i = 0; i < soluongnguoidung; i++) {
                danhsachnguoidung[i].hienthithongtinnguoidung();

            }
        }

};
int main()
{
    thuvien ThuVien;
    nguoidung NguoiDung;
    cout << "nhap thong tin sach" << endl;
    ThuVien.themsach();
    ThuVien.themsach();
    cout << "nhap thong tin nguoi dung" << endl;
    NguoiDung.nhapthongtinnguoidung();
    ThuVien.themsach();
    cout << "danh sach sach trong thu vien" << endl;
    ThuVien.hienthinguoidung();
    string ISBN;
    cout << "nhap ISBN sach muon muon" << endl;
    getline(cin, ISBN);
    ThuVien.chomuonsach(ISBN);
    cout << "danh sach sau khi muon 1 cuon" << endl;
    cout << "nhap ISBN muon tra" << endl;
    getline(cin, ISBN);
    ThuVien.trasach(ISBN);
    cout << "danh sach sau khi tra 1 cuon" << endl;
    ThuVien.hienthisach();
    return 0;   
}
 
