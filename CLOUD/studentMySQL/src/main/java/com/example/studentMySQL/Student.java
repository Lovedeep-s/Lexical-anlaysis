package com.example.studentMySQL;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity // This tells Hibernate to make a table out of this class
public class Student {
	//The @Idannotation is inherited from javax.persistence.Id, 
	// indicating the member field below is the primary key of current entity. 
	@Id 
	// The @GeneratedValue annotation is used to specify how the primary key should be generated.
	@GeneratedValue(strategy=GenerationType.AUTO) 
	private Integer  id;
	private String name;
	
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
}
