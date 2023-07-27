import requests
import json

headers = {}

def get(url):
    r = requests.get(url, headers=headers)
    status_code = r.status_code
    json = r.json()
    print(status_code, json)
    return status_code, json

def post(url, payload):
    r = requests.post(url, json=payload, headers=headers)
    status_code = r.status_code
    json = r.json()
    print(status_code, json)
    return status_code, json

def put(url, payload):
    r = requests.put(url, json=payload, headers=headers)
    status_code = r.status_code
    json = r.json()
    print(status_code, json)
    return status_code, json

def delete(url):
    r = requests.delete(url, headers=headers)
    status_code = r.status_code
    json = r.json()
    print(status_code, json)
    return status_code, json

def main():
    status_code, login_info = post("http://localhost:3000/login", { "email" : "mathieu.jaeger@outlook.com", "password" : "coucou" })
    if(status_code == 200):
        headers["Authorization"] = "Bearer " + login_info["token"]
        _, user_r = get("http://localhost:3000/user")
        _, todos_r = get("http://localhost:3000/user/todos")

        _, user_r = get("http://localhost:3000/users/7")

        _, user_r = get("http://localhost:3000/todos")
        _, user_r = get("http://localhost:3000/todos/1")

if __name__ == "__main__":
    main()