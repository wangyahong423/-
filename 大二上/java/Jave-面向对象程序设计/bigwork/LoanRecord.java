package bigwork;

import java.util.Date;
import java.util.Scanner;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.text.DateFormat;


public class LoanRecord {
	Scanner input = new Scanner(System.in);
	protected Member m= new Member();
	protected Produce p=new Produce();
	public void borrowRecord(Member m,Produce p) {
		this.m=m;
		this.p=p;
		System.out.println("请输入你的姓名：");
		String name =input.nextLine();
		m.setName(name);
		try {
			DateFormat d1=DateFormat.getDateTimeInstance(); 
			String s1=d1.format(new Date()); 
			Writer writer = new FileWriter("F:\\record.txt",true);
			writer.write(s1+":"+"借阅："+m.toString()+"\t"+p.toString()+"\r\n");
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void returnRecord(Member member,Produce p) {
		try {
			DateFormat d1=DateFormat.getDateTimeInstance(); 
			String s1=d1.format(new Date());
			Writer writer = new FileWriter("F:\\record.txt",true);
			writer.write(s1+":"+m.getName()+"归还：" +p.name+"\r\n");
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
