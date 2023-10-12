package com.example.Tvlist.controller;

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

import com.example.Tvlist.model.Tv;

@RestController
@RequestMapping("/TvApi")
public class tvApi {
	List<Tv> Tvl ;
	tvApi(){
		Tvl = new ArrayList<Tv>();
	}
	@GetMapping("{id}")
	Tv getTv(@PathVariable String id )
	{
		for(int i =0; i<Tvl.size();i++)
		{
			if(Tvl.get(i).getId().compareTo(id) ==0)
			{
				return Tvl.get(i);
			}
		}
		return null;
		
	}
	@GetMapping
	List <Tv> getTvlist()
	{
		return Tvl;
	}
	
	@PostMapping
	String createtv(@RequestBody Tv tv) {
		Tvl.add(tv);
		return "Tv with tv id : " + tv.getId() + " has been added to the list";	
		}
	@PutMapping
	String UpdateTv(@RequestBody Tv tv)
	{
		for(int i =0; i<Tvl.size();i++)
		{
		if(tv.getId().compareTo(Tvl.get(i).getId())==0) {
			Tvl.remove(i);
			Tvl.add(tv);
			return "Tv with id  "+tv.getId()+" has been updated";
		}
		}
		return "Tv with id "+tv.getId()+" is not in the List";
		
	}
	@DeleteMapping("{id}")
	String deletetv(@PathVariable String id){
		
		for (int i=0; i<Tvl.size(); i++) {
			if(Tvl.get(i).getId().compareTo(id)==0) {
				Tvl.remove(i);
				return  "Tv with id  "+id+" has been removed";
			}
		}
		return "Tv with id  "+id+" is not in the List";		
	}

}
