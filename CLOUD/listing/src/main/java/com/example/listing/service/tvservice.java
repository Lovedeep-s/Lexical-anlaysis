package com.example.listing.service;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.ResponseBody;

import com.example.listing.model.tvlist;
import com.example.listing.repo.tvRepository;
@Service
public class tvservice {
	@Autowired 
	private tvRepository tv;
	public @ResponseBody String Saveor(tvlist tvr )
	{
		
	    tv.save(tvr);
	    return "Saved";
	}
	
	public @ResponseBody Iterable<tvlist> showall()
	{
		return tv.findAll();
	}
	public @ResponseBody tvlist showinfo(String i)
	{
		int l=Integer.parseInt(i);
		tvlist ut = tv.findById(l).orElse(null) ;
		
		return ut;
	}
	public @ResponseBody String update(tvlist tvr )
	{
		tvlist utv = tv.findById(tvr.getI()).orElse(null) ;
		if(utv != null)
		{	utv.setName(tvr.getName());
			utv.setId(tvr.getId());
			utv.setPrice(tvr.getPrice());
		    tv.save(utv);
		    return "updated";
			
		}
		else
		{
			tv.save(tvr);
			return "new entry";
		}
		
	}
	public @ResponseBody String delete(int i)
	{
		tv.deleteById(i);
		return "Deleted";
	}
	
	
}
