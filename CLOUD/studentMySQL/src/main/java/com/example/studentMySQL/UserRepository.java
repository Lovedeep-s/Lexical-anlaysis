package com.example.studentMySQL;

import org.springframework.data.repository.CrudRepository;

public interface UserRepository extends CrudRepository<Student, Integer>{

}
