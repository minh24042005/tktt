import java.io.Serializable;
import java.util.*;
public class MyData implements Serializable{
    private int ngay;
    private int thang;
    private int nam;

	public MyData() {
		this.ngay=0;
		this.thang=0;
		this.nam=0;
	}

	public MyData(int ngay, int thang, int nam) {
		this.ngay = ngay;
		this.thang = thang;
		this.nam = nam;
	}
	public MyData(MyData d) {
		   this.ngay=d.ngay;
		   this.thang=d.thang;
		   this.nam=d.nam;
	}
	public void makecopy(MyData d) {
	   this.ngay=d.ngay;
	   this.thang=d.thang;
	   this.nam=d.nam;
	}
    public void hienthi() {
    	System.out.println("ngay" + ngay + "thang " + thang + "nam" + nam);
    }
    public void nhap() {
    	Scanner sc= new Scanner(System.in);
    	while(!sc.hasNextInt()) {
    		System.out.println("nhap sai nhap lai ngay");
    		sc.next();
    		System.out.println("nhap ngay");
    	}
      ngay=sc.nextInt();
      System.out.println("nhap thang");
  	while(!sc.hasNextInt()) {
		System.out.println("nhap sai nhap lai thang");
		sc.next();
		System.out.println("nhap thang");
	}
  thang=sc.nextInt();
  System.out.println("nhap nam");
	while(!sc.hasNextInt()) {
		System.out.println("nhap sai nhap lai nam");
		sc.next();
		System.out.println("nhap nam");
	}
  nam=sc.nextInt();
    }
    public boolean hople(){
          if(thang < 1 || thang > 12 || ngay < 1)
        	  return false;
          if(thang == 2 && (nam % 4 == 0))
        	  return (ngay<=29);
          int songaymax[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31};
          return (ngay <= songaymax[thang]);
    }
    
    public MyData ngayhomsau() {
    if((ngay == 28) && (thang==2) && (nam%4==0) ) {
    	MyData x= new MyData(29,2,nam);
      return x;
    }
    MyData d= new MyData(ngay+1,thang,nam);
    int songaymax[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31};
    if(d.ngay > songaymax[d.thang]) {
    	d.ngay=1;
        d.thang++;
    }
    if(d.thang > 12) {
    	d.thang=1;
    	d.nam++;
    }
    return d;
}
    public MyData congNgay(int n) {
    	MyData d= new MyData(ngay,thang,nam);
    	for(int i=0;i<n;i++) {
        d=d.ngayhomsau();
    	}
    	return d;
}
    public String toString() {
    	return "ngay" + ngay + "thang " + thang + "nam" + nam;
    }
    public boolean equals(MyData d) {
    	return this.ngay==d.ngay && this.thang==d.thang && this.nam==d.nam;
    }
    public int layngay() {
    	return ngay;
    }
    public int laythang() {
    	return thang;
    }
    public int laynam() {
    	return nam;
    }
}
