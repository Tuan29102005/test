#include <iostream>
#include <cstring>


using namespace std;

struct date {
    int ngay, thang, nam;
};

class sanpham {
    date ngaynhap;
    char* ten;
    char* id;
    int soluong;
    float dongia;
    float thanhtien;
    static int soloaisanpham;

public:
    sanpham()  {
       
    }

    sanpham(const char* t, const char* i, date n, int sl, float dg)
        : ngaynhap(n), soluong(sl), dongia(dg), thanhtien(sl* dg) {
        ten = new char[strlen(t) + 1];
        strcpy(ten, t);
        id = new char[strlen(i) + 1];
        strcpy(id, i);
    }

    sanpham(date n, const char* t, const char* i, float dg)
        : ngaynhap(n), dongia(dg), soluong(0), thanhtien(0) {
        ten = new char[strlen(t) + 1];
        strcpy(ten, t);
        id = new char[strlen(i) + 1];
        strcpy(id, i);
    }

    ~sanpham() {
        delete[] ten;
        delete[] id;
    }

    sanpham operator+(const sanpham& sp) const {
        sanpham tong;
        tong.thanhtien = this->thanhtien + sp.thanhtien;
        return tong;
    }

    friend ostream& operator<<(ostream& os, const sanpham& sp) {
        os << "Ten san pham: " << (sp.ten ? sp.ten : "N/A") << endl;
        os << "ID: " << (sp.id ? sp.id : "N/A") << endl;
        os << "Ngay nhap: " << sp.ngaynhap.ngay << "/" << sp.ngaynhap.thang << "/" << sp.ngaynhap.nam << endl;
        os << "So luong: " << sp.soluong << endl;
        os << "Don gia: " << sp.dongia << endl;
        os << "Thanh tien: " << sp.thanhtien << endl;
        return os;
    }

    void nhapDuLieu() {
        cout << "Nhap ten san pham: ";
        char buffer[100];
        cin.ignore();
        cin.getline(buffer, 100);
        ten = new char[strlen(buffer) + 1];
        strcpy(ten, buffer);

        cout << "Nhap ID: ";
        cin.getline(buffer, 100);
        id = new char[strlen(buffer) + 1];
        strcpy(id, buffer);

        cout << "Nhap ngay nhap (ngay thang nam): ";
        cin >> ngaynhap.ngay >> ngaynhap.thang >> ngaynhap.nam;

        cout << "Nhap so luong: ";
        cin >> soluong;

        cout << "Nhap don gia: ";
        cin >> dongia;

        thanhtien = soluong * dongia;
    }

    void gandulieu(date n, const char* t, const char* i, int sl, float dg) {
        ngaynhap = n;
        delete[] ten;
        ten = new char[strlen(t) + 1];
        strcpy(ten, t);
        delete[] id;
        id = new char[strlen(i) + 1];
        strcpy(id, i);

        soluong = sl;
        dongia = dg;
        thanhtien = soluong * dongia;
    }



    static void SoLoaiSanPham(int sl) {
        soloaisanpham = sl;
    }

    static int LaySoLoaiSanPham() {
        return soloaisanpham;
    }
};

int sanpham::soloaisanpham = 0;

int main() {
    int soLoai;
    cout << "Nhap so loai san pham: ";
    cin >> soLoai;
    sanpham::SoLoaiSanPham(soLoai);

    
    sanpham sp1;
    cout << "Nhap thong tin san pham 1:\n";
    sp1.nhapDuLieu();

    sanpham sp2;
    cout << "Nhap thong tin san pham 2:\n";
    sp2.nhapDuLieu();

   
    cout << "\nThong tin san pham 1:\n";
    cout << sp1 << endl;

    cout << "\nThong tin san pham 2:\n";
    cout << sp2 << endl;

   
    sanpham sp3 = sp1 + sp2;
    cout << "\nTong thanh tien cua hai san pham: " << sp3 << endl;

    return 0;
}

