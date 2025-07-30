import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.*;
public class SVMSSV {
     public static void main(String[] args) {
    	 Scanner sc= new Scanner(System.in);
		ThueBaoInternet tb= new ThueBaoInternet();	
		tb.nhap();
		tb.hienthi();
		System.out.println("nhap n");
		int n=sc.nextInt();
		ThueBaoInternet a[] = new ThueBaoInternet[n];
		for(int i=0;i<n;i++) {
			a[i] = new ThueBaoInternet();
			a[i].nhap();
		}
		int max=0;
		ThueBaoInternet tbmax = a[0];
		for(int i=0;i<n;i++) {
			if(a[i].tinhcuoc() > max ) {
				max=a[i].tinhcuoc();
				tbmax= a[i];
			}
		}
		System.out.println("thue bao max ");
		tbmax.hienthi();
		int sum=0;
		for(int i=0;i<n;i++) {
            sum=sum+a[i].tinhcuoc();
			}
		System.out.println("tong "+ sum);
	    
		System.out.println("nhap cccd");
		String cccdnhap = sc.nextLine();
		boolean f=false;
		for(int i=0;i<n;i++) {
            if(a[i].equals(cccdnhap)) {
            	a[i].hienthi();
            	f=true;
            } 
            }
		if(!f) {
			System.out.println("loi");
			}


		
		}
     
}
