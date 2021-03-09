#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define maxnum 500

//Fungsi utama
void main(){
    float total=0.0,num1;
    int num,i=0,reset=1,numerator=1;

    //Tampilan menu
    printf("\nKALKULATOR\n");

    while (true){
        printf("----------\n1.Penjumlahan\n2.Pengurangan\n3.Perkalian\n4.Pembagian\n5.Perpangkatan\n6.Polynomial Function Integral\n7.Reset\n8.Exit\n\n");
        printf("Masukkan operasi: ");
        scanf("%d",&num);

        //Validas numerator
        while (num<=0 || num>7){
            printf("Operator invalid. Masukkan operator: ");
            scanf("%d",&num);
        }

        //Pemasukan angka pertama
        if ((num>0 && num<6) && reset==1){
            printf("Masukkan angka pertama: ");
            scanf("%f",&total);

        } else if(num==8){
            exit(1);
        }

        switch(num){

            // case penjumlahan
        case 1:
            do{
                printf("Insert numerand: ");
                scanf("%f",&num1);
                total = total + num1;

                printf("\nTambahkan lagi? (0/1)\n");
                scanf("%d",&numerator);

            } while(numerator==1);

            printf("----------\nHasil Operasi: %.2f\n",total);

            printf("Ingin mereset kalkulator? (0/1)\n");
            scanf("%d",&reset);
            break;

            //Case pengurangan
        case 2:
            do{
                printf("----------\nInsert numerand: ");
                scanf("%f",&num1);
                total = total - num1;

                printf("\nKurangi lagi? (0/1)\n");
                scanf("%d",&numerator);

            } while (numerator==1);

            printf("----------\nHasil Operasi: %.2f\n",total);

            printf("Ingin mereset kalkulator? (0/1)\n");
            scanf("%d",&reset);
            break;

            //Case perkalian
        case 3:
            do{
                printf("----------\nInsert numerand: ");
                scanf("%f",&num1);
                total = total*num1;

                printf("\nIngin mengalikan lagi? (0/1)\n");
                scanf("%d",&numerator);

            } while (numerator==1);

            printf("----------\nHasil Operasi: %.2f\n",total);

            printf("\n----------\nIngin mereset kalkulator? (0/1)\n");
            scanf("%d",&reset);
            break;

            //Case pembagian
        case 4:
            do{
                printf("----------\nInsert numerand: ");
                scanf("%f",&num1);
                total = total/num1;

                printf("\nIngin membagi lagi? (0/1)\n");
                scanf("%d",&numerator);

            } while (numerator==1);

            printf("----------\nHasil Operasi: %.2f\n",total);

            printf("\n----------\nIngin mereset kalkulator? (0/1)\n");
            scanf("%d",&reset);
            break;

            //Case perpangkatan
        case 5:
            do{
                printf("----------\nInsert power: ");
                scanf("%f",&num1);
                total = pow(total,num1);

                printf("\nPangkatkan lagi? (0/1)\n");
                scanf("%d",&numerator);

            } while (numerator==1);

            printf("----------\nHasil Operasi: %.5f\n",total);

            printf("Ingin mereset kalkulator? (0/1)\n");
            scanf("%d",&reset);
            break;

            //Case Integral Polinomial
        case 6:
            printf("\n\nPOLYNOMIAL INTEGRAL CALCULATOR\n------------------------------\n\n");
            do{
                numerator = integral();
            } while(numerator==1);

            reset = 1;
            break;

        case 7:
            total = 0.0;
            reset = 1;
            break;
        }
    }
}

//Fungsi integral Polinomial
int integral(){
    int numerator,i,num,N,a,b;
    float total=0.0,fungsi[maxnum],temp2=0.0,temp=0.0,xkiri;

    printf("Masukkan pangkat tertinggi polinom: ");
    scanf("%d",&num);

    printf("Masukkan fungsi polinom:\n");

    //Pemasukan Fungsi
    for (i=0;i<num+1;i++){
        printf("Koefisien ke-%d: ",i);
        scanf("%f",&fungsi[i]);
    }

    //Batas kanan
    printf("Masukkan batas kanan: ");
    scanf("%d",&b);

    //Batas kiri
    printf("\nMasukkan batas kiri: ");
    scanf("%d",&a);

    //Partisinya
    printf("Masukkan jumlah partisi: ");
    scanf("%d",&N);

    //Inisiasi kondisi awal integral
    float part = (b-a)/(float)N;
    printf("Partisi: %.5f\n",(float)N);
    int k=0;
    xkiri = (float)a;

    //Loopnig riemann
    while (k<N){
        temp = 0.0;
        temp2 = 0.0;

        for (i=0;i<num+1;i++){
            temp = temp + (float)fungsi[i]*pow(xkiri,i);
            temp2 = temp2 + (float)fungsi[i]*pow(xkiri+part,i);
        }

        total = total + (temp+temp2);

        xkiri = xkiri + part;
        k++;
    }

    total = 0.5*part*total;

    //output
    printf("Hasil: %.3f",total);
    printf("\n\n----------\nUlangi integral? (0/1)\n");
    scanf("%d",&numerator);

    return numerator;
}
