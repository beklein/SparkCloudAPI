# SparkCloudAPI

A Pyhton module to access your Spark Core using the [Spark Cloud API](http://docs.spark.io/#/api/) /v1. 

This modules requires the [requests](http://requests.readthedocs.org/en/latest/) package, to install just type:

```
pip install requests
```

## Currently working

* generating a acces token
* list all your tokens
* deleting an access token
* calling a function
* getting a variable value

## Example

1. go to [Spark Build](https://www.spark.io/build/) and create a new App, type in any name you want
2. copy the example.cpp into the editor
3. hit "Verify" and then "Flash"
4. get your deviceID ready, just hit "Cores"
5. open your Terminal, start Python and write

create a new object for your Spark Core

```
>>> from SparkCloudAPI import SparkCore
>>> myCore = SparkCore('YOUREMAIL@ADRESS.com', 'YOURPASSWORD', 'YOURDEVICEID')
```

get an access token

```
>>> print myCore.getAccessToken()
3141592653589793238462643383279502884197

```
get all your access tokens

```
>>> print myCore.getAllTokens()
[
  {
    "token": "3141592653589793238462643383279502884197",
    "expires_at": "2014-05-23T15:58:14.959Z",
    "client": "spark"
  }
]
```

delete an access token

```
>>> print myCore.deleteToken('3141592653589793238462643383279502884197')
{
  "ok": true
}
```

turn your LED on

```
>>> print myCore.sendFunctionRequest('switchLED', 'on')
{
  "id": "628318530717958647692528",
  "name": "test_core",
  "last_app": null,
  "connected": true,
  "return_value": 1
}
```

turn your LED off

```
>>> print myCore.sendFunctionRequest('switchLED', 'off')
{
  "id": "628318530717958647692528",
  "name": "test_core",
  "last_app": null,
  "connected": true,
  "return_value": 1
}
```

get the value for your variable

```
>>> print myCore.readVariable('someVariable')
42
```