package bigwork;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Book extends Produce {
	private String author;
	private String ISBN;
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getISBN() {
		return ISBN;
	}
	public void setISBN(String iSBN) {
		ISBN = iSBN;
	}
	public void add(Produce p) {
		if(p instanceof Book) {
			Book b=(Book) p;
			System.out.println("������ͼ����Ϣ��");
			System.out.println("���");
			b.number=input.nextLine();
			System.out.println("����");
			b.name=input.nextLine();
			System.out.println("����");
			b.quantity=input.nextInt();
			String huiche0=input.nextLine();
			System.out.println("����");
			b.author=input.nextLine();
			System.out.println("ISBN��");
			b.ISBN=input.nextLine();
			try {
				FileReader fileReader =new FileReader("F:\\produce.txt");
				Writer writer=new FileWriter("F:\\produce.txt",true);
				writer.write(this.toString()+"\r\n");
				writer.close();
				this.tag=1;
				System.out.println("ͼ����ӳɹ�");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "��ţ�"+number+"���ƣ�"+name+"������"+quantity+"���ߣ�"+author+"ISBN�ţ�"+ISBN;
	}
}
