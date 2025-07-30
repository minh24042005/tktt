import java.io.Serializable;
import java.util.*;
public class ThueBaoInternet implements Serializable,Comparable<ThueBaoInternet> {
       private String tentaikhoan;
       private String hotenchu;
       private String cccd;
       private String diachi;
       private MyData ngaydangky;
       private int tocdo;
       
       //ham xay dung mac nhien co tham so
	public ThueBaoInternet(String tentaikhoan, String hotenchu, String cccd, String diachi, MyData ngaydangky,
			int tocdo) {
		this.tentaikhoan = tentaikhoan;
		this.hotenchu = hotenchu;
		this.cccd = cccd;
		this.diachi = diachi;
		this.ngaydangky = ngaydangky;
		this.tocdo = tocdo;
	}

      // ham xay dung mac nhien khong tham so
	public ThueBaoInternet() {
		this.tentaikhoan = new String();
		this.hotenchu = new String();
		this.cccd = new String();
		this.diachi = new String();
		this.ngaydangky = new MyData();
		this.tocdo = 0;
	}
    // ham xay dung sao chep
	public ThueBaoInternet(ThueBaoInternet tb) {
		this.tentaikhoan=tb.tentaikhoan;
		this.hotenchu=tb.hotenchu;
		this.cccd=tb.cccd;
		this.diachi=tb.diachi;
		this.ngaydangky=tb.ngaydangky;
		this.tocdo=tb.tocdo;
	}
	//ham xay dung sao chep sau
	public void makecopy(ThueBaoInternet tb) {
		this.tentaikhoan=tb.tentaikhoan;
		this.hotenchu=tb.hotenchu;
		this.cccd=tb.cccd;
		this.diachi=tb.diachi;
		this.ngaydangky=tb.ngaydangky;
		this.tocdo=tb.tocdo;
	}
	
	public void nhap() {
		Scanner sc= new Scanner(System.in);
		System.out.println("nhap ten tai khoan");
		this.tentaikhoan=sc.nextLine();
		System.out.println("nhap ho ten");
		this.hotenchu=sc.nextLine();
		System.out.println("nhap cccd");
		this.cccd=sc.nextLine();
		System.out.println("nhap dia chi");
		this.diachi=sc.nextLine();
		System.out.println("nhap ngay dang ky");
		this.ngaydangky.nhap();
		System.out.println("nhap toc do");
		this.tocdo=sc.nextInt();
	}
	public void hienthi() {
		System.out.println(" ten tai khoan " + tentaikhoan + " ho ten  " + hotenchu + " cccd  " + cccd + " dia chi  " + diachi + " ngay dang ky  " + ngaydangky +" toc d0  " +tocdo);
	}
    public int tinhcuoc() {
    	if(tocdo==60) return 165;
    	if(tocdo==80)  return 180;
    	if(tocdo==110) return 230;
    	if(tocdo==140) return 280;
    	if(tocdo==250) return 480;
    	else return -1;
    }
    
    public boolean tocDoCaoHon(ThueBaoInternet tb) {
    	return this.tocdo > tb.tocdo;
    }
    
    public boolean equals(ThueBaoInternet tb) {
          return this.cccd==tb.cccd;
    }
   public MyData layNgayDangKy() {
      return this.ngaydangky;
   }


public String getTentaikhoan() {
	return tentaikhoan;
}


public void setTentaikhoan(String tentaikhoan) {
	this.tentaikhoan = tentaikhoan;
}


public String getHotenchu() {
	return hotenchu;
}


public void setHotenchu(String hotenchu) {
	this.hotenchu = hotenchu;
}


public String getCccd() {
	return cccd;
}


public void setCccd(String cccd) {
	this.cccd = cccd;
}


public String getDiachi() {
	return diachi;
}


public void setDiachi(String diachi) {
	this.diachi = diachi;
}


public MyData getNgaydangky() {
	return ngaydangky;
}


public void setNgaydangky(MyData ngaydangky) {
	this.ngaydangky = ngaydangky;
}


public int getTocdo() {
	return tocdo;
}


public void setTocdo(int tocdo) {
	this.tocdo = tocdo;
}
public int compareTo(ThueBaoInternet tb) {
	return this.ngaydangky.toString().compareTo(tb.ngaydangky.toString());
} 
}
