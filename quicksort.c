#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int degistirme(int dizi[],int pvt,int son)//burada rasgele secilen pivotu dizinin sonuncu indisine att�m. diziyi d�nd�rd�m.
{
	int temp;
	temp=dizi[pvt];
	dizi[pvt]=dizi[son];
    dizi[son]=temp;
    return dizi[100];
}
int bolme(int dizi[],int bas,int son)//burada dizi quicksort fonksiyonundan  gelen terimler siralayarak b�ld�m.
{
	int random = bas + rand() % (son - bas);// burada random pivot aliyorum ve ona ggre siraliyorum
	printf("\nRasgele Pivot:  %d",dizi[random]);
    degistirme(dizi,random,son);
	int pvt = dizi[son];        // burada dizinin sonuncusunu pivota att�m.i de olu�an diziyi artirmak i�in kullandim.
    int i = (bas - 1);         //burada dizinin  ilk elemaninda degistirmecimiz icin -1 kullandim en basta.
    for (int j = bas; j <son ; j++)
    {
        if (dizi[j] <= pvt)// pvt diziden buyuk olursa ilk elemandan itibaren kontrolu yapmak icin degistirme yaptim.
        {
            i++;       // i yidegistirecegim eleman indisi.
            dizi[100]=degistirme(dizi,i,j);//i ile dizinin indisi j yi degistirdim.
        }
    }

     degistirme(dizi,i+1,son);//burada sonda kalan bir i oldugu i�in bunu da ekledim.
     printf("\n");
      for(int k=bas;k<son+1;k++){
     printf("%d  ",dizi[k]);
      }
    return (i + 1);//i +1 dondurdum.
}
void quickSort(int dizi[], int ilk, int son)
{
    if (ilk < son)  // bunu b�lerken sonunda ilk sona e�it veya b�y�k oldu�unda dolay� b�yle bir ko�ul kulland�m.
    {
        int pvt = bolme(dizi, ilk, son);//pivot burada bizim yine b�ld���m�z dizide sonuncu eleman (i+1),
        quickSort(dizi,ilk, pvt - 1);//eger pivottan kucuk 2 sayi varsa kontrolu yapmak icin kullandim.
        quickSort(dizi, pvt + 1,son);//eger pivottan buyuk 2 sayi varsa kontrolu yapmak icin kullandim.
    }
}


int main()
{
srand(time(NULL));
 int n,i,j;
 int lock[100],key[100],tmp[100];
 printf("Oda sayisini giriniz(n)...:\n");// kullanicidan oda sayisini aliyorum(n)
 scanf("%d",&n);
 printf("Lock(kilit) dizisini giriniz..\n");//lock dizisinide kullanicidan aliyorum.
 for(i=0;i<n;i++){
	scanf("%d", &lock[i]);
 }
 for(i=0;i<n;i++){
    tmp[i]=lock[i];// burada lock dizisinden key dizi uretecegim icin tmp dizisi kullandim.//
 }
 for(i=n-1;i>=0;i--){
  j=rand()%(i+1);//burada rasgele indis olu�turmak icin kullandim.ve degistirme yaptim.
  degistirme(tmp,i,j);
}
printf("key[i]:   ");
for(i=0;i<n;i++){
    key[i]=tmp[i];// key i yi temp esitledim.
	printf("%d ",key[i]);
}
printf("\nyeni lock\t");
quickSort(lock, 0, n-1);// burada quicksorta yollad�m.
printf("\n");
 for(i=0;i<n;i++){
     printf("%d  ",lock[i]);
}
printf("\nyeni key\t");
quickSort(key,0,n-1);// key dizisini sirqqaliyorum.
printf("\n");
 for(i=0;i<n;i++){
     printf("%d  ",key[i]);
}
printf("\n");
for(i=0;i<n;i++){// burada uyum kntrol� yaoiyorum.
	  for(j=0;j<n;j++){
		if(lock[i]==key[j]){
			printf("lock[%d] ile key[%d] uyumlu..\n",i+1,j+1);
		}
	  }
}
}
