package com.example.Tvlist.model;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class Tv {
	  private int i;
	  private String id;
	  private String name;
	  private float price;
		public Tv(String id, String name, float price) {
			super();
			this.id = id;
			this.name = name;
			this.price = price;
		}
		public Tv() {
			super();
		}
		
		public int getI() {
			return i;
		}
		public void setI(int i) {
			this.i = i;
		}
		public String getId() {
			return id;
		}
		public void setId(String id) {
			this.id = id;
		}
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public float getPrice() {
			return price;
		}
		public void setPrice(float price) {
			this.price = price;
		}
		
	


}