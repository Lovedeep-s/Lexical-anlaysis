import requests
import json
# Define the base URL of the REST API
base_url = "http://localhost:8080/TvApi"

# Function to make a GET request
def get_data(endpoint):
    url = base_url + endpoint
    # print(url)
    response = requests.get(url)
    if response.status_code == 200:
        return response.json()
    else:
        print(f"Failed to GET data. Status code: {response.status_code}")
        return None



# # Function to make a POST request
# def post_data(endpoint, parmas = None):
#     url = base_url + endpoint
#     response = requests.post(url, params=parmas)
#     if response.status_code == 201:
#         return response.json()
#     else:
#         print(f"Failed to POST data. Status code: {response.status_code}")
#         return None
    
# Function to make a POST request
def post_data(endpoint, data):
    url = base_url + endpoint
    response = requests.post(url, json=data)
    if response.status_code == 201 or response.status_code == 200:
        print("Data added successfully.")
        return 1
    else:
        print(f"Failed to POST data. Status code: {response.status_code}")
        return 0

# Function to make a DELETE request
def delete_data(endpoint,params = None):
    url = base_url + endpoint
    response = requests.delete(url,params=params)
    if response.status_code == 204 or response.status_code == 200:
        print("Data deleted successfully.")
    else:
        print(f"Failed to DELETE data. Status code: {response.status_code}")

def put_data(endpoint, data):
    url = base_url + endpoint
    response = requests.put(url, json=data)
    if response.status_code == 201 or response.status_code == 200:
        print("Data updated successfully.")
        return 1
    else:
        print("Failed to PUT data. Status code: {response.status_code}")
        return 0


    
while True:
    
    switch = input("\n 1 for GET\n 2 for POST\n 3 for DELETE\n 4 for PUT\n 5 for exit\n Enter choice: ")
    if switch == "1":
        l= input("Enter the id or all to get all data:")
        if l=="all":
            if __name__ == "__main__":
                # Example GET request 
                data = get_data("/all")
                # ndata = data.json()
                ndata = json.dumps(data, indent=4)
                if data:
                    print("GET data:", ndata)
        if l!="all":
            if __name__ == "__main__":
                # Example GET request 
                p="/"+str(l)
                # print(p)
                data = get_data(p)
                ndata = json.dumps(data, indent=4)
                if data:
                    print("GET data:", ndata)
    elif switch == "2":
        
        # Example POST request
        id = input("Enter the id: ")
        name = input("Enter the name: ")
        price = input("Enter the price: ")
        new_data = {'id': id, 'name': name, 'price': price}
        created_data = post_data("/add", new_data)
        d = json.dumps(new_data, indent=4)
        if created_data :
            print("POST data:", d)

    elif switch == "3":
        j=input("Enter the id to be deleted: ")
        # Example DELETE request
        delete_params = {'i': j}
        delete_data("/delete",params=delete_params)
    elif switch == "4":
        # Example Put request
        i=input("Enter the id to be updated: ")
        id = input("Enter the new id: ")
        name = input("Enter the name: ")
        price = input("Enter the price: ")
        new_data = {'i': i ,'id': id, 'name': name, 'price': price}
        put_data("/update", new_data)
    elif switch == "5":
        break
    else:
        print("Invalid input. Please try again.")
