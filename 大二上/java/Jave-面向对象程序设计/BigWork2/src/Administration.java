import java.util.*;
import java.io.*;

public class Administration {
	private static VIP[] vipArray;
	private static Book[] bookArray;
	private static DVD[] dvdArray;
	private static LoaningRecord[] recordArray;
	
	public VIP[] getVIP(){
		return vipArray;
	}
	
	public Commodity[] getDVD(){
		return dvdArray;
	}
	public Commodity[] getBook(){
		return bookArray;
	}
	public int InitializationVIP(int num){
		vipArray = new VIP[num];
		return num;
	}
	
	public int InitializationDVD(int num){
		dvdArray = new DVD[num];
		return num;
	}
	public int InitializationBook(int num){
		bookArray = new Book[num];
		return num;
	}
	
	public void addVIP(){
		int i;
		for(i=0;i<vipArray.length;i++){
			System.out.println("�������"+(i+1)+"����Ա��Ϣ��");
			vipArray[i] = new VIP();
			Scanner a = new Scanner(System.in);
			String id = a.next();
			vipArray[i].setID(id);
			String name = a.next();
			vipArray[i].setName(name);
			String phone = a.next();
			vipArray[i].setPhone(phone);
			
		}
		
	}
	public void searchVIP(String str){
		for(int i=0;i<vipArray.length;i++){
			String x = str;
			String y = vipArray[i].getName();
			if(y.contains(x))
				System.out.println("���ƣ�"+vipArray[i].getName()+"\t"+"��ţ�"+vipArray[i].getID()+"\t"+"�绰��"+vipArray[i].getPhone());
		}
		System.out.println();
		
		
	}
	public void modify(String name,String a,String b,String c){
		for(int i=0;i<vipArray.length;i++){
			String x = name;
			String y = vipArray[i].getName();
			if(y.contains(x)){
				vipArray[i].setID(a);
				vipArray[i].setName(b);
				vipArray[i].setPhone(c);
			}
				}
	}
	public void printing_AllVIP(){
		for(int i=0;i<vipArray.length;i++){
			System.out.println(vipArray[i].toString());
		}
	}
	
	public void addDVD(){
		int i;
		for(i=0;i<dvdArray.length;i++){
			System.out.println("�������"+(i+1)+"��DVD��Ϣ��");
			dvdArray[i] = new DVD();
			Scanner a = new Scanner(System.in);
			String name = a.next();
			dvdArray[i].setCommodityName(name);
			String id = a.next();
			dvdArray[i].setID(id);
			Double number = a.nextDouble();
			dvdArray[i].setNumber(number);
			String ISRC = a.next();
			dvdArray[i].setISRC(ISRC);

		}
	} 
	public void searchDVD(String str){
		for(int i=0;i<dvdArray.length;i++){
			String x = str;
			String y = dvdArray[i].getCommodityName();
			if(y.contains(x))
				System.out.println("���ƣ�"+dvdArray[i].getCommodityName()+"\t"+"��ţ�"+dvdArray[i].getId()+"\t"+"����"+bookArray[i].getNumber()+"\t"+"ISRC��"+dvdArray[i].getISRC());
			else
				System.out.println("��DVD�����ڣ�");
		}
		System.out.println();
		
	}
	public void printing_AllDVD(){
    	for(int i=0;i<dvdArray.length;i++){
    		System.out.println(dvdArray[i].toString());
    	}
    	
    } 
	public void borrowDVD(String str){
		double a;
		for(int i=0;i<dvdArray.length;i++){
			if(dvdArray[i].getCommodityName().equals(str)){
				a=dvdArray[i].getNumber()-1;
				dvdArray[i].setNumber(a);
			}
			else
				System.out.println("��DVD�����ڣ�");
		}
		
	}
	public void returnDVD(String str){
		double a;
		for(int i=0;i<dvdArray.length;i++){
			if(dvdArray[i].getCommodityName().equals(str)){
				a=dvdArray[i].getNumber()+1;
				dvdArray[i].setNumber(a);
			}
			else
				System.out.println("��DVD�����ڣ�");
		}
	}
	
	public void addBook(){
		int i;
		for(i=0;i<bookArray.length;i++){
			System.out.println("�������"+(i+1)+"���鼮��Ϣ��");
			bookArray[i] = new Book();
			Scanner a = new Scanner(System.in);
			String name = a.next();
			bookArray[i].setCommodityName(name);
			String id = a.next();
			bookArray[i].setID(id);
			Double number = a.nextDouble();
			bookArray[i].setNumber(number);
			String writer = a.next();
			bookArray[i].setWriter(writer);
			String ISBN = a.next();
			bookArray[i].setISBN(ISBN);
			
		}
	} 
	
	public void searchBook(String str){
		for(int i=0;i<bookArray.length;i++){
			String x = str;
			String y = bookArray[i].getCommodityName();
			if(y.contains(x))
				System.out.println("���ƣ�"+bookArray[i].getCommodityName()+"\t"+"��ţ�"+bookArray[i].getId()+"\t"+"����"+bookArray[i].getNumber()+"\t"+"���ߣ�"+bookArray[i].getWriter()+"\t"+"ISBN��"+bookArray[i].getISBN());
			else
				System.out.println("��ͼ�鲻���ڣ�");
		}
		System.out.println();
		
	}
	public void printing_AllBook(){
    	for(int i=0;i<bookArray.length;i++){
    		System.out.println(bookArray[i].toString());
    	}
    	
    } 
	
	public void borrowBook(String str){
		double a;
		for(int i=0;i<bookArray.length;i++){
			if(bookArray[i].getCommodityName().equals(str)){
				a=bookArray[i].getNumber()-1;
				bookArray[i].setNumber(a);
			}
			else
				System.out.println("��ͼ�鲻���ڣ�");
		}
		
	}
	public void returnBook(String str){
		double a;
		for(int i=0;i<bookArray.length;i++){
			if(bookArray[i].getCommodityName().equals(str)){
				a=bookArray[i].getNumber()+1;
				bookArray[i].setNumber(a);
			}
			else
				System.out.println("���鼮�����ڣ�");
		}
	}
	
	public void writeVIP(){
		try{
			FileReader fileReader = new FileReader("D:\\java\\BigWork2\\src\\vip.txt");
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String str=bufferedReader.readLine();
			if(str!=null){
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\vip.txt"));
				for(int i=0;i<vipArray.length;i++){
					writer.write(str+vipArray[i].toString() + "\r\n");
				}
				writer.close();
			}
			else{
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\vip.txt"));
				for(int i=0;i<vipArray.length;i++){
					writer.write(vipArray[i].toString() + "\r\n");
				}
				writer.close();
			}
		}catch (IOException e) {
			e.printStackTrace();
		}

	}
	public void writeDVD(){
		try{
			FileReader fileReader = new FileReader("D:\\java\\BigWork2\\src\\DVD.txt");
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String str=bufferedReader.readLine();
			if(str!=null){
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\DVD.txt"));
				for(int i=0;i<dvdArray.length;i++){
					writer.write(str+dvdArray[i].toString() + "\r\n");
				}
				writer.close();
			}
			else{
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\DVD.txt"));
				for(int i=0;i<dvdArray.length;i++){
					writer.write(dvdArray[i].toString() + "\r\n");
				}
				writer.close();
			}
		}catch (IOException e) {
			e.printStackTrace();
		}

	}
	public void writeBook(){
		try{
			FileReader fileReader = new FileReader("D:\\java\\BigWork2\\src\\Book.txt");
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String str=bufferedReader.readLine();
			if(str!=null){
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\Book.txt"));
				for(int i=0;i<bookArray.length;i++){
					writer.write(str+bookArray[i].toString() + "\r\n");
				}
				writer.close();
			}
			else{
				Writer writer = new FileWriter(new File("D:\\java\\BigWork2\\src\\book.txt"));
				for(int i=0;i<bookArray.length;i++){
					writer.write(bookArray[i].toString() + "\r\n");
				}
				writer.close();
			}
		}catch (IOException e) {
			e.printStackTrace();
		}

	}
	
	

	
	
}
