<!-- Copyright 2018 Moreal -->

CatWar Server Architecture
==========================

## Scenario

### 유저
1. MISC: User Entered
2. Request: Check Resource Update to 스토리지

### 스토리지
If Check user's version is same with itself version

3. Response: No Update to 유저

Else

3. Response: Exists Update signal and Docker's endpoints(IP) to 유저  
    ```
    Process: Load Balance가 File Transfer Docker's endpoints 리턴 
    ```

```
If Balancer is dead  
    Observer will be there instead it
```

### 유저
After Update Process  

4. Request: Try Login

### 프로필
OnGetRequest
```
Process: Add Job to Job Queue
```

OnPushedToJobQueue (Job Thread Pool)
```
Process: Get Job
Process: Process the Job
Process: Check id, pw from UserDB(SQL)

if login is Success:
    Process: Create Random Token (id + random() + salt) // TODO: Check less Hash Collision
    Process: Insert (ip. token, endpoint)
    Process: Create SSL Session () // TODO: Think about replacing this server into HTTPS WebServer
    Response: Login Success & Token & Lobby

else:
    Response: Login Failed
```

### 유저
OnSuccessLogin:
```
Process: Save Token
Process: SSL Connection End
Process: Set State into Lobby & Save Lobby endpoint
Request: Get User Data like lv, ranking etc..
```

OnFailedLogin:
```
Process: Dialog "Your login is failed"
Process: Game End
```

### 로비
OnGetRequest
```
if req.token == token:
    if req.ip != ip:
        Response: Login Again // Refresh Token(?)
    
    Response: req.value from DB
else:
    Response: Access Denined
```

OnStartRequest
```
if req.token == token:
    Process: resp = Route Play Server Endpoints by Play Server by users..
    Response: resp.endpoint
else:
    Response: Access Denined
```

### 유저
OnSuccessJoin
```
Process: Set State into Play
Process: Save Play Server endpoint
Request: Get Observer end point from router
```

### 플레이
OnGetObserverResponse
```
Process: Execute one more observer Docker image
Response: The Image's endpoint to connect
```

## OPTIONS
- token이 사용되지 않고 10분 이상 있을 경우 Refresh를 요청한다
- IP가 계속 바뀌지 않는 유선망을 타겟으로 한다

## Architecture Image
![Image](CatWar-Server-Architecture-Play-Server.png)