package com.example.listing.contoller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.example.listing.model.tvlist;
import com.example.listing.service.tvservice;
@RestController
@RequestMapping(path="/TvApi")
public class tvapi {
	@Autowired
	private tvservice tvs;

	  @PostMapping(path="/add") // Map ONLY POST Requests
	  public @ResponseBody String addNewUser (@RequestBody tvlist tv) {
		  tvs.Saveor(tv);
		  return "saved" ;
		  
	    
	  }
	  @GetMapping("{id}")
	  public @ResponseBody tvlist getUsers(@PathVariable String id)
	  {
		  return tvs.showinfo(id);
		  
	  }
	  @GetMapping(path="/all")
	  public @ResponseBody Iterable<tvlist> getAllUsers() {
	    // This returns a JSON or XML with the users
	    return tvs.showall();
	  }
	  @PutMapping(path="/update")
	   public String updatetv(@RequestBody tvlist tv) {
		  return tvs.update(tv);
	   }
	  @DeleteMapping(path="/delete")
	  public String deletetv( @RequestParam int i ) {
	  return tvs.delete(i);
   }

}
