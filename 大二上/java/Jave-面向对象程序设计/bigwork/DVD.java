package bigwork;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class DVD extends Produce{
	private String ISRC;

	public String getISRC() {
		return ISRC;
	}

	public void setISRC(String iSRC) {
		ISRC = iSRC;
	}
	public void add(Produce p) {
		if(p instanceof DVD) {
			DVD d= (DVD) p;
			System.out.println("������DVD��Ϣ��");
			System.out.println("���");
			d.number=input.nextLine();
			System.out.println("����");
			d.name=input.nextLine();
			System.out.println("����");
			d.quantity=input.nextInt();
			String huiche0=input.nextLine();
			System.out.println("ISRC��");
			d.ISRC=input.nextLine();
			try {
				FileReader fileReader =new FileReader("F:\\produce.txt");
				Writer writer=new FileWriter("F:\\produce.txt",true);
				writer.write(this.toString()+"\r\n");
				writer.close();
				System.out.println("DVD��ӳɹ�");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "��ţ�"+number+"���ƣ�"+name+"������"+quantity+"ISRC�ţ�"+ISRC;
	}
}
