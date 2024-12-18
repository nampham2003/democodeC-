#include <conio.h>
#include <iostream>
#include <string.h>
#define MAX 100

struct SinhVien{
    char ten[40];
    char NS[20];
    long int MSV;
    char lop[30];
    float dToan, dtriet, dltc;
	float dtb ;
};

typedef SinhVien SV;
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuatN(SV a[], int n);
void tinhDTB(SV &sv);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);
void showStudent(SV a[], int n);

int main(){
    int key;
    char fileName[] = "DSSV.txt";
    int n;
    SV arraySV[MAX];
    int soluongSV = 0;
    bool daNhap = false;
    
    SV a[n];
    while(true){
        system("cls");
        printf("MENU QUAN LY SINH VIEN KHOA CONG NGHE THONG TIN");
        printf("\n*********************************************************************");
        printf("\n** 1. NHAP THONG TIN SINH VIEN.                                    **");
        printf("\n** 2. XUAT DANH SACH SINH VIEN.                                    **");
        printf("\n** 3. TINH DIEM TRUNG BINH SINH VIEN.                              **");
        printf("\n** 4. SAP XEP SINH VIEN THEO THU TU TANG DAN CUA DIEM TRUNG BINH.  **");
        printf("\n** 5. XEP LOAI HOC SINH.                                           **");
        printf("\n** 6. NHAP XUAT DU LIEU SINH VIEN VAO FILE.                        **");
        printf("\n** 0. BAN CHON THOAT CHUONG TRINH.                                 **");
        printf("\n*********************************************************************");
		printf("\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon:1. Nhap Thong Tin sinh vien!");
                do{
        		printf("\nNhap so luong SV: "); scanf("%d", &n);
    			}while(n <= 0);
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon: 2.Xuat Thong Tin sinh vien!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
            	 if(daNhap){
                    printf ("\nBam da chon: 3.Tinh Diem TB cua sinh vien.");
                    showStudent(a, n);
                }else{
                	printf ("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon: 4.Sap xep SV theo DTB!");
                    sapxep(a, n);
                    showStudent(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon: 5.Xep loai SV!");
                    xeploaiN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
                if(daNhap){
                    printf("\nBan da chon: 6.Xuat DS SV!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
 
void tinhDTB(SV &sv){
    sv.dtb = (sv.dToan + sv.dtriet + sv.dltc)/3;    
}
 
void nhap(SV &sv){
	printf("\nNHap Ma Sinh Vien: ");scanf("%d",&sv.MSV);
    printf("\nNhap Ten: "); fflush(stdin); gets(sv.ten);
    printf("\nNhap Ngay Sinh: "); gets(sv.NS);
    printf("\nNhap Lop: "); fflush(stdin); gets(sv.lop); 
    printf("\nNhap Diem Toan: ");scanf("%f",&sv.dToan);
    printf("\nNhap Diem Triet: ");scanf("%f",&sv.dtriet);
    printf("\nNhap Diem Lap Trinh C: ");scanf("%f",&sv.dltc);
    tinhDTB(sv);
}
 
void nhapN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void showStudent(SV a[], int n) {
    printf("\n_____________________________________\n");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n| STT\t| Ma sinh vien\t| Ho va ten\t| Ngay sinh\t| Lop\t| Toan\t| Triet\t| Lap trinh\t| Diem TB |");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    for(int i = 0; i < n; i++) {
        printf("\n| %d", i + 1);
        printf("\t| %d", a[i].MSV);
        printf("\t| %s", a[i].ten);
        printf("\t| %s", a[i].NS);
        printf("\t| %s", a[i].lop);
        printf("\t| %.2f\t| %.2f\t| %.2f", a[i].dToan, a[i].dtriet, a[i].dltc);
        printf("\t\t| %.2f    |", a[i].dtb);
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n");
    printf("\n_____________________________________\n");
} 

void xuatN(SV a[], int n){
    printf("\n_____________________________________\n");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n| STT\t| Ma sinh vien\t| Ho va ten\t| Ngay sinh\t| Lop\t| Toan\t| Triet\t| Lap trinh |");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    for(int i = 0;i < n;++i){
        printf("\n| %d", i + 1);
        printf("\t| %d", a[i].MSV);
        printf("\t| %s", a[i].ten);
        printf("\t| %s", a[i].NS);
        printf("\t| %s", a[i].lop);
        printf("\t| %.2f\t| %.2f\t|   %.2f    |", a[i].dToan, a[i].dtriet, a[i].dltc);  
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n");
    printf("\n_____________________________________\n");
}
 
void sapxep(SV a[], int n){
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dtb > a[j].dtb){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

using namespace std;
void xeploai(SV sv){
    if(sv.dtb >= 8) printf("\t|   Gioi   |");
    else if(sv.dtb >= 6.5) printf("\t|   Kha    |");
    else if(sv.dtb >= 4) printf("\t|    TB    |");
    else printf("\t|   Yeu    |");
}
 
void xeploaiN(SV a[], int n){
    printf("\n____________________________________\n");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    printf("\n| STT\t| Ma sinh vien\t| Ho va ten\t| Ngay sinh\t| Lop\t| Xep loai |");
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    for(int i = 0;i < n;++i){
        printf("\n| %d", i + 1);
        printf("\t| %d", a[i].MSV);
        printf("\t| %s", a[i].ten);
        printf("\t| %s", a[i].NS);
        printf("\t| %s", a[i].lop);  	
        xeploai(a[i]);
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    printf("\n");
    printf("\n____________________________________\n");
}
 
void xuatFile(SV a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp, "%5d%20s%5s%20s%10s%10s%10s%10s\n","MSV", "Ho Ten","NS", "Lop", "DToan", "Dtriet", "Dltc", "DTB");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%20s%5s%20s%10f%10f%10f%10f\n",a[i].MSV, a[i].ten, a[i].NS, a[i].lop, a[i].dToan, a[i].dtriet, a[i].dltc, a[i].dtb);
    }
    fclose (fp);
}
