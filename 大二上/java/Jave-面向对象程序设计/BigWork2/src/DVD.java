
public class DVD extends Commodity {
	private String ISRC;
	private static DVD[] dvdArray;
	
	public DVD[] getDVD(){
		return dvdArray;
	}
	
//	public DVD(String commodityName, String id, double number, String iSRC) {
//		super(commodityName, id, number);
//		ISRC = iSRC;
//	}

	public String getISRC() {
		return ISRC;
	}
	public void setISRC(String str){
		ISRC=str;
	}

	public String toString() {
		return "DVD [DVD���ƣ�" + getCommodityName() + ", DVD��ţ�" + getId() + ", ������" + getNumber()+ ", ISRC�ţ�" + ISRC + "]";
	}
	

}
