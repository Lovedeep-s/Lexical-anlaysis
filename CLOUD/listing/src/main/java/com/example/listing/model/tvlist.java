package com.example.listing.model;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity 
@Table
public class tvlist {
	  @Id
	  @GeneratedValue(strategy=GenerationType.IDENTITY)
	  private int i;
	  @Column
		private String id;
	  @Column
	  private String name;
	  @Column
	  private float price;
		public tvlist(String id, String name, float price) {
			super();
			this.id = id;
			this.name = name;
			this.price = price;
		}
		public tvlist() {
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
