package bigwork;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class Member {
	Scanner input=new Scanner(System.in);
	//��š��������绰
	private int num;
	private String name;
	private String phoneNum;
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPhoneNum() {
		return phoneNum;
	}
	public void setPhoneNum(String phoneNum) {
		this.phoneNum = phoneNum;
	}
	
	public void add() {
		System.out.println("���");
		this.num=input.nextInt();
		String huiche=input.nextLine();
		System.out.println("�绰");
		this.phoneNum=input.nextLine();
		System.out.println("����");
		this.name=input.nextLine();
		try {
			FileReader fileReader =new FileReader("F:\\member.txt");
			Writer writer=new FileWriter("F:\\member.txt",true);
			writer.write(this.toString()+"\r\n");
			writer.close();
			System.out.println("��Ա��ӳɹ�");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public boolean find(String str) {
		if(this.name.equals(str)) {
			System.out.println(this.toString());
			return true;
		}else {
			return false;
		}
	}
	public void display(Member m) {
		System.out.println(m.toString());
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "��ţ�"+num+" ���֣�"+name+" �绰��"+phoneNum;
	}
}
