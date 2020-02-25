
public class Commodity {
	private String commodityName;
	private String id;
	private double number;
	
	
//	public Commodity(String commodityName, String id, double number) {
//		this.commodityName = commodityName;
//		this.id = id;
//		this.number = number;
//		
//	}
	

	public String getCommodityName() {
		return commodityName;
	}
	public void setCommodityName(String str){
		this.commodityName = str;
	}

	public String getId() {
		return id;
	}
	public void setID(String str){
		this.id = str;
	}

	public double getNumber() {
		return number;
	}
	public void setNumber(double str){
		this.number = str;
	}

	public String toString() {
		return "Commodity [Ãû³Æ=" + commodityName + ", ±àºÅ=" + id + ", ÊýÁ¿=" + number + "]";
	}

}
