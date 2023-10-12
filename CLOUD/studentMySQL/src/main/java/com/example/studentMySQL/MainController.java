package com.example.studentMySQL;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller // This means that this class is a Controller
@RequestMapping(path="/studentSQL") // This means URL's start with /demo (after Application path)
public class MainController {
  @Autowired // This means to get the bean called userRepository
         // Which is auto-generated by Spring, we will use it to handle the data
  private UserRepository userRepository;

  @PostMapping // Map ONLY POST Requests
  public @ResponseBody String addNewStudent (@RequestBody Student stu) {
    userRepository.save(stu);
    return "Saved";
  }

  @GetMapping
  public @ResponseBody Iterable<Student> getAllStudents() {
    // This returns a JSON or XML with the users
    return userRepository.findAll();
  }
  
  @GetMapping("{id}")
  public @ResponseBody Student getStudent(@PathVariable Integer id) {
	  return userRepository.findById(id).get();
  }
  
  
  @DeleteMapping("{id}")
  public void deleteStudent(@PathVariable Integer id) {
	  userRepository.deleteById(id);
  }
}