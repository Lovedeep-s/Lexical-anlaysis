package com.example.listing.repo;


import org.springframework.data.jpa.repository.JpaRepository;
import com.example.listing.model.tvlist;

public interface tvRepository extends JpaRepository<tvlist, Integer> {

	
}
