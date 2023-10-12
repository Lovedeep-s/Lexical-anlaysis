package com.example.student.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.student.model.Student;

@RestController
@RequestMapping("/studentApi")
public class StudentAPI {
	
	List<Student> studentList;
	
	StudentAPI(){
		studentList = new ArrayList<Student>();
	}
	
	
	// Fetch whole list
	
	@GetMapping
	List<Student> get(){
		return studentList;
	}
	
	
	// Fetch a student from list have id as id of Student
	@GetMapping("{id}")
	Student getStudent(@PathVariable String id){
		
		for (int i=0; i<studentList.size(); i++) {
			if(studentList.get(i).getId().compareTo(id)==0) {
				return studentList.get(i);
			}
		}
		return null;
	}
	
	// Add a student to studentList
	@PostMapping
	String createStudent(@RequestBody Student stu) {
		studentList.add(stu);
		return "Student with studednt id "+stu.getId()+" has been added to the List";
	}
	
	// Update a Student
	@PutMapping
	String updateStudent(@RequestBody Student stu) {
		for (int i=0; i<studentList.size(); i++) {
			if(stu.getId().compareTo(studentList.get(i).getId())==0) {
				studentList.remove(i);
				studentList.add(stu);
				return "Student with studednt id "+stu.getId()+" has been updated";
			}
		}
		return "Student with studednt id "+stu.getId()+" is not in the List";		
	}
	
	
	// Delete a Student
	
	@DeleteMapping("{id}")
	String deleteStudent(@PathVariable String id){
		
		for (int i=0; i<studentList.size(); i++) {
			if(studentList.get(i).getId().compareTo(id)==0) {
				studentList.remove(i);
				return  "Student with studednt id "+id+" has been removed";
			}
		}
		return "Student with studednt id "+id+" is not in the List";		
	}
	
	

}
