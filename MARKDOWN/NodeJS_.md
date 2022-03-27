##  Node JS
  
  
###  1. Basic Information about Node
  
-----------------------------------
* Node is a runtime environment for executing JS code and it allows javascript to run on the server side
* Essentially, Node is a C++ program that embeds Chrome’s v8 engine, the fastest JS engine in the world. 
* We use Node to build fast and scalable networking applications. It’s a perfect choice for `building RESTful services`. 
* Node applications are `single-threaded`. That means a single thread is used to serve all clients. 
* Node applications are `asynchronous` or non-blocking by default. That means when the application involves I/O operations (eg accessing the file system or the network), the thread doesn’t wait (or block) for the result of the operation. It is released to serve other clients. 
* This architecture makes Node ideal for building I/O-intensive applications. 
* You should avoid using Node for CPU-intensive applications, such as a video encoding service. Because while executing these operations, other clients have to wait for the single thread to finish its job and be ready to serve them. 
* In Node, we `don’t have browser environment objects` such as window or the document object. Instead, we have other objects that are not available in browsers, such as objects for working with the file system, network, operating system, etc.
</br>
</br> 
  
###  2. Node Console
  
---
run `node` in terminal
  
###  3. API Data Format
  
---
> XML
* Extended Markup Language
* XML is syntacticly similar to HTML, but it does not describe presentation like HTML does
```XML
<person>
	<age>21</age>
	<name>Dylan</name>
	<city>Guangzhou</city>
</person>
```
  
> JSON
* Javascript Object Notation
* looks exactly like Javascript objects, but everything is a string
```Javascript
// the same example as XML above
{
	"person": {
		"age": "21",
		"name": "Travis",
		"city": "Guangzhou"
	}
}
```
  
  
###  2. Node Module System
  
-------------------------
* Global objects (<b>`global`</b>): 
<br>
Example: `console.log()`, `setTimeout()`, `setInterval()` ...
<br>
These are the shorten version of `global.console.log()`, `global.setTimeout()`,...
```Javascript
var message = 'new message';
console.log(global.message) // undefined because message is only available at the current file
```
<br>
  
* Module(<b>`module`</b>):
<br>
`console.log(module);`
<br>
In Node, every file is a module. Functions and variables are defined in the scope of the module.
  
<br>
  
* Export Module functions/variables(`module.exports`)
```Javascript
// Example 1 (export several things)
var url = 'http://www.google.com';
function display(message) {
    console.log(message);
}
// add the display function to the exports class with the name `displayFunction`
module.exports.displayFunction = display;
// add the url to the exports class with the name `url`
module.exports.url = url;
```
```Javascript
// when console.log(module) with the file above, we can get the `exports` element of module contains:
exports: { displayFunction: [Function: display], url: 'http://www.google.com' }
```
  
```Javascript
// Example 2 (alternative way of exporting a single thing)
function display(message) {
    console.log(message);
}
// we don't have to specify the name of the elements inside the exports object if we export in this way
module.exports = display;
```
  
<br>
  
* load module(`requrie`):
<br>
`require('relative-path-to-desired-module');`
<br>
```Javascript
// Using the two exports examples above
  
// Example 1
const utility = require('relative-path');
console.log(utility.url); // http://www.google.com
utility.displayFunction('message'); // message
  
// Example 2
const utility = require('relative-path');
utility('message') // message
```
  
<br>
  
* Module Wrapper Function: in each module, there is a function that wraps everything (created by Node)
```Javascript
// The wrapper function is something like below:
(function (exports, require, module, __filename, __dirname) {
    ...
});
// This means inside each module, `exports`, `require`, ... are local to that module
console.log(__filename) // absolute path to this file
```
  
<br>
  
* <a href="https://nodejs.org/api/modules.html">Built-in module: </a>
> `path` module
```Javascript
// built in `path` module
const path = require('path');
var pathObj = path.parse(__filename);
  
// built in `os` module
// Without Node, javascript is only working on the browser (dealing with `window` or `document`)
// Node allows javascript to be exercised outside the browser and have access to the operating system
const os = require(`os`);
var totalMemory = os.totalmem();
var freeMemory = os.freemem();
```
> File system (`fs`) module
```Javascript
// built in `fs` module (file system)
const fs = require('fs');
// for each function of `fs`, it has both synchronous and asynchronous versions
// always prefer to use asynchronous version which is more efficient and Node has only a single thread
  
// synchronous version:
// get all the names of the files of a specific path
const files = fs.readdirSync('./');
  
// asynchronous version:
fs.readdir('./', (err, files) => {
    if (err) {
        console.log('Error', err);
    } else {
        console.log('Result', files);
    }
});
```
> `events` module
```Javascript
// built in `events` module
// Order of the code matters (setup a listener first before raise an event)
  
// EventEmitter is a class
const EventEmitter = require('events');
  
// emitter is an instance of the class EventEmitter
const emitter = new EventEmitter();
  
// Register a listener
// 'messageLogged' is the name of the event
// the function will be called once the listener is called
emitter.on('messageLogged', function() {
    console.log('Listener called');
});
  
// Raise an event
emitter.emit('messageLogged');
```
  
```Javascript
// built in `events` module with arguments
const EventEmitter = require('events');
const emitter = new EventEmitter();
  
// the name of the arguments is arg (can be any)
emitter.on('Login', function(arg) {
    console.log('Listener called', arg);
});
  
// Raise an event with arguments
emitter.emit('Login', {userName: 'lin', age: 21});
```
  
```Javascript
// use the event raiser from other file
// App.js
const Logger = require('./Logger');
const logger = new Logger();
  
logger.on('messageLogged', (arg) => {
    console.log('Listener called', arg);
});
  
logger.log('message');
  
//Logger.js
const EventEmitter = require('events');
class Logger extends EventEmitter {
    // the function of a class does not requrie `function` in the front
    // because it's a method
    log(message) {
        console.log(message);
        // `this` indicates the `Logger` class
        // since the `Logger` class extends EventEmitter,
        // it has all the capabilities as the `EventEmitter` class
        this.emit('messageLogged', {id: 1, url: 'http://'});
    }
}
  
module.exports = Logger;
```
> `http` module
```Javascript
const http = require('http');
  
const server = http.createServer((req, res) => {
    // create the rounte '/' with response 'Hello World'
    if (req.url === '/') {
        res.write('Hello World');
        res.end();
    }
  
    // create another route '/api/courses/' with response JSON format
    if (req.url === '/api/courses') {
        res.write(JSON.stringify([1,2,3]));
        res.end();
    }
});
  
// The server listens to the port number 3000
server.listen(3000);
  
console.log('Listen on port 3000...');
```
  
> `devDependencies`
* devDependencies will not be uploaded to the production version
* When we install the deveDependencies, `npm install dev_dependency_name --save-dev` to tell the node that it's a devDependency
  
> Remove a dependency
* `npm un package_name`
  
<br>
  
###  3. Node Package Manager
  
--------------------------
* For the front end, we can just include the script tag to include libraries (eg. bootstrap), but there is no script tag for the node, so we can use npm to download the packages
> `package.json`
* run `npm init` or `npm init --yes`(for shortcut)
* create `package.json` before adding any npm packages
  
> Install npm packages
* `npm install package_name`
* installed packages will be stored in node_modules
* don't have to use `npm install package_name --save` anymore
* install a specific version of a package: `npm install package_name@version_number`
  
> Use npm packages
```Javascript
// terminal:
npm install underscore
  
  
// app.js:
// Node will check first if 'underscore' is a core module
// then check if 'underscore' is a file or folder
// then check if 'underscore' is in the node_modules
var _ = require('underscore');
```
  
> npm packages source control
* Don't include node_modules in source control (eg. github) because we can get the dependencies by using `package.json`
  
> Semantic versioning in `package.json`
```Javascript
// the version of `mongoose` in the package.json as below
{
    ...
    "dependencies": {
        "mongoose": "^5.9.22"
    }
}
```
* According to the semantic versioning, `5.9.22` version means `major.minor.patch` version. 
    * patch version increases: bugs fixed to be more stable
    * minor version increases: add new features without breaking the api
    * major version increases: potentially break the api depends on the current version
  
* `^` in "mongoose" : "^5.9.22" means depends on any versions of `mongoose` with major version `5` (`5.x` version)
* `~` in "~5.9.22" means depends on versions `5.9.x` (major and minor versions should be the same)
* "5.9.22" means the dependency has to be exact version `5.9.22`
  
> Listing the installed packages
* `npm list` show every dependency and its dependency
* `npm list --depth=0` show only the dependency in the `package.json`
  
> View the npm packages
* `npm view package_name` display all the info of the package
* `npm view package_name dependencies` display only the area (dependencies in this case) of the package
  
  
<br>
  
###  3. Restful APIs Using Express
  
---------------------------------
> RESTful services
* REST defines a set of conventions for creating HTTP services:
    * POST: to create a resource
    * PUT: to update it
    * GET: to read it
    * DELETE: to delete
* HTTP protocol connects between `client` and `server`
  
> Express
* `npm install express`
* Express http `get` method
```Javascript
// express http `get` method
const express = require('express');
const app = express();
  
// `/` is the end point for this case
app.get('/', (req, res) => {
    res.send('Hello World');
});
  
// `/api/courses` is the end point
app.get('/api/courses', (req, res) => {
    res.send([1,2,3]);
});
  
app.listen(3000, () => console.log('Listening on port 3000...'));
```
  
> `nodemon`
* `npm install i -g nodemon`
* any updates on code can be restarted automatically without manually close the terminal and restart
* instead of using `node file_name.js`, use `nodemon file_name.js` to run the file
  
> `Environment Variables`
* In order to make the `get` example more appropriate in both dev and prod versions, we need to use the environmental variables to provide a proper port for both cases
    ```Javascript
    const port = process.env.PORT || 3000;
    app.listen(port, () => console.log(`Listening on port ${port}...`));
    ```
  
* Set environment variable: 
    ```Javascript
    // terminal: 
    // set the environmental variable `PORT` to be 5000
    export PORT=5000;
    ```
  
> Route Parameters
* original `get` method
  
    ```Javascript
    // return all the courses from the database
    app.get('/api/courses', (req, res) => {
        ...
    });
    ```
  
* to get a specific course, include the id in the route
    ```Javascript
    // /:id is a parameter of the route
    // id can also be replaced by courseID or something else
    app.get('/api/courses/:id', (req, res) => {
        res.send(req.params.id); // we can access the id from the route
    })
  
    // several params in route
    app.get('/api/posts/:year/:month', (req, res) => {
        res.send(req.params); // params objects
    });
  
    // query object: 
    // start with `?` and use `&` to connect different query parameters
    // http://localhost:3000/api/posts?name=dylan&age=21
    app.get('/api/posts', (req, res) => {
        res.send(req.query); // {"name": "dylan", "age": 21}
    });
    ```
  
  
> Handling HTTP `GET` Requests
```Javascript
const express = require('express');
const app = express();
  
const courses = [
    { id: 1, name: 'course1' },
    { id: 2, name: 'course2' },
    { id: 3, name: 'course3' }
]
  
// get all the courses
app.get('/api/courses', (req, res) => {
    res.send(courses);
});
  
// find the course with a given id
app.get('/api/courses/:id', (req, res) => {
    const course = courses.find(course => course.id === parseInt(req.params.id));
    // when the course is not found
    if (!course) {
        return res.status(404).send('The course with the given id is not found');
    }
    res.send(course);
});
```
  
> Handling HTTP `POST` request
```Javascript
const express = require('express');
const app = express();
  
// express.json() returns a middleware
app.use(express.json()); // enable express parsing json 
  
const courses = [
    { id: 1, name: 'course1' },
    { id: 2, name: 'course2' },
    { id: 3, name: 'course3' }
]
  
// get all the courses
app.get('/api/courses', (req, res) => {
    res.send(courses);
});
  
app.post('/api/courses', (req, res) => {
    const course = {
        id: courses.length + 1,
        name: req.body.name // assume req.body is an object with name as the property
    };
    courses.push(course);
    res.send(course); // and we can display the pushed course on the page
});
  
app.listen(3000, () => console.log('Listening on port 3000...'));
  
```
  
> Postman
* We can use the chrome postman extention
* Use the same example as above. Enter the objects in the `body` section as below and click send
* ![alt text](https://github.com/DylanLin29/Notes/blob/master/Web%20Development/Images/Postman%20example.png )
* When send a post request, we can add the data inside `body` of Postman
  
> Validation of the requests
* Simple validation of the requests
    ```Javascript
    app.post('/api/courses', (req, res) => {
        // simple validation
        if (!req.body.name || req.body.name.length < 3) {
            // status code 400 means bad request
            res.status(400).send('Name is required and should be minimum 3 characters');
            // return so that the remaining code will not be executed
            return;
        }
        const course = {
            id: courses.length + 1,
            name: req.body.name // assume req.body is an object with name as the property
        };
        courses.push(course);
        res.send(course); // and we can display the pushed course on the page
    });
    ```
* Validation using an npm package `joi`
    * `npm install joi`
    ```Javascript
    // validation using `joi` example
    const express = require('express');
    const app = express();
    const Joi = require('joi');
    app.use(express.json()); // enable express parsing json 
  
    const courses = [
        { id: 1, name: 'course1' },
        { id: 2, name: 'course2' },
        { id: 3, name: 'course3' }
    ]
  
    app.post('/api/courses', (req, res) => {
        const schema = {
            // indicate that the name is string type
            // at least 3 characters
            // required: users have to input the name
            name: Joi.string().min(3).required()
        };
  
        // validate the body with the schema
        // return a promise
        const result = Joi.validate(req.body, schema);
  
        // if there is no error, result.error is null
        if(result.error) {
            res.status(400).send(result.error.details[0].message); // or send the original error: `result.error` (more complicated)
            return;
        }
  
        const course = {
            id: courses.length + 1,
            name: req.body.name
        };
        courses.push(course);
        res.send(course);
    });
    ```
  
> Handling `PUT` Requests (update)
```Javascript
// Update document example
const express = require('express');
const app = express();
const Joi = require('joi');
app.use(express.json()); // enable express parsing json 
  
const courses = [
    { id: 1, name: 'course1' },
    { id: 2, name: 'course2' },
    { id: 3, name: 'course3' }
]
  
// since we are updating a specific document
// we need to get its id
app.put('/api/courses/:id', (req, res) => {
    // Steps: 
    // 1. Look up the course. If not exists, return 404
    // 2. Validate the request. If invalid, return 400 - Bad request
    // 3. Update the course. Return the updated course
  
    // Step 1: Look up
    const course = courses.find(course => course.id === parseInt(req.params.id));
    // when the course is not found
    if (!course) {
        return res.status(404).send('The course with the given id is not found');
    }
  
    // Step 2: Validate
    const schema = {
        name: Joi.string().min(3).required()
    };
  
    const result = Joi.validate(req.body, schema);
  
    if(result.error) {
        res.status(400).send(result.error.details[0].message); // or send the original error: `result.error` (more complicated)
        return;
    }
  
    // Step 3: Update
    course.name = req.body.name;
    res.send(course);
});
  
app.listen(3000, () => console.log('Listening on port 3000...'));
```
  
> Handling HTTP `Delete` Requests
```Javascript
const express = require('express');
const app = express();
const Joi = require('joi');
app.use(express.json()); // enable express parsing json 
  
const courses = [
    { id: 1, name: 'course1' },
    { id: 2, name: 'course2' },
    { id: 3, name: 'course3' }
]
  
app.delete('/api/courses/:id', (req, res) => {
    // Steps: 
  
    // 1. Look up the course. If not exists, return 404
    const course = courses.find(course => course.id === parseInt(req.params.id));
    // when the course is not found
    if (!course) {
        res.status(404).send('The course with the given id is not found');
        return;
    }
  
    // 2. Delete and return the removed course
    const index = courses.indexOf(course);
    courses.splice(index, 1);
  
    res.send(course);
});
  
app.listen(3000, () => console.log('Listening on port 3000...'));
```
  
> Middleware
* Middleware gives you access to `req` and `res` in the apps request -> response cycle
* Middleware usually are called between processing the request and sending the response in the application.
* Middleware functions are called in sequence. There is usually a chain of functions that are called one after the other
* must call `next()` (unless it's the last function in the chain). Otherwise, the request will just hang and eventually timeout.
* Examples of middleware functions: 
    ```Javascript
    // Example 1
    const express = require('express');
    const app = express();
    app.get('/', (req, res) => {
        res.send('Hello World');
    });
  
    // Example 2
    // express.json() is a middleware function which has req, res, next as parameters
    // it parses the request body and set the req.body when it meets json object
    app.use(express.json());
    ```
* <a href="https://medium.com/@jamischarles/what-is-middleware-a-simple-explanation-bb22d6b41d01">More Info About Middleware</a>
* <a href="https://stackoverflow.com/questions/23259168/what-are-express-json-and-express-urlencoded/51844327#51844327">Some built-in middleware</a>
  
> Customized Middleware
```Javascript
const express = require('express');
const app = express();
  
// `next` indicates next middleware
// and pass control to the next middleware
app.use(function(req, res, next) {
    console.log('logging...');
    // If we don't have this line
    // the middleware can't be passed to the next middleware
    // since the req and res cycle isn't end, nothing can be displayed for the website
    next();
});
```
  
```Javascript
// Use middleware function from other file
  
// index.js: 
const express = require('express');
const app = express();
const logger = require('./logger');
app.use(logger);
  
  
// logger.js: 
function logger(req, res, next) {
    console.log('logging...');
    next();
}
  
module.exports = logger;
```
  
> Environments
* Two ways of getting environments
    ```Javascript
    process.env.NODE_ENV // `undefined` by default
    ```
  
    ```Javascript
    const express = require('express');
    const app = express();
    app.get('env') // `development` by default
    ```
* Set environment variables
    ```Javascript
    // in terminal: 
    // for example, set the NODE_ENV to development
    export NODE_ENV=development
    ```
* Use `config` package to set configuration
  
    ```Javascript
    // terminal: 
    npm install config
    ```
  
    * create a file named `config`.<br>
    Inside the `config` file: create `development.json`, `production.json` (or maybe `staging.json`)<br>
    The name before `.json` is the name in `process.env.NODE_ENV`
  
    * Example 1 of using `config` package
    ```Json
    // config/production.json:
    {
        "name": "My Express App - Production",
        "mail": {
            "host": "prod-mail-server"
        }
    }
  
    // config/development.json:
    {
        "name": "My Express App - Development",
        "mail": {
            "host": "dev-mail-server"
        }
    }
  
    // terminal:
    export NODE_ENV=development
    ```
    ```Javascript
    // index.js
    const config = require('config');
    console.log(`name: ${config.get('name')}`); // name: My Express App - Development
    console.log(`host: ${config.get('mail.host')}`); // host: dev-mail-server
    ```
  
    * Example 2 of using `config` package<br>
    create `custom-environment-variables` file under `config`
    ```JSON
    // terminal: 
    export app_password=1234
  
    // config/custom-environment-variables
    {
        // map mail.password with the environment variable `app_password`
        "mail" : {
            "password": "app_password"
        }
    }
    ```
  
    ```Javascript
    // index.js
    const config = require('config');
    console.log(`app_password: ${config.get('mail.password')}`); // 1234
    ```
  
> Use `debug` package for debugging
* `npm install debug`
* Instead of writing `console.log(...)`, we can use the debug function from the `debug` package
* Example:
    ```Javascript
    // terminal: 
  
    export DEBUG=app:startUp // set the environment variable of `debug` package 
    export DEBUG=app:startUp,app:db // show multiple debuggers' results
    export NODE_ENV=development
  
  
    // index.js
    const startUpDebugger = require('debug')('app:startUp');
    const dbDebugger = require('debug')('app:db'); // we also can defile more deBugger function. By convention, one debugger for each file.
    const express = require('express');
    const app = express();
  
    if (app.get('env') === 'development') {
        // If we set the DEBUG=app:startUp, the line below will be displayed. Otherwise, this line won't be displayed
        startUpDebugger("It's development mode");
    }
    ```
  
> Templating Engines `pug`
* Create the template for html
* `npm install pug`
```Javascript
// index.js
const express = require('express');
const app = express();
app.set('view engine', 'pug'); // we can use express to set and we don't have to require
app.set('views', './views'); // all the view engines' files inside the `views` folder
  
app.get('/', (req, res) => {
    // instead of using `res.send`, use `res.render` to use `pug` template
    res.render('index', {title: 'My Express App', message: 'Hello'});
});
app.listen(3000, () => console.log('Listening on port 3000...'));
  
  
// views/index.js (where we define the view engine, can be other than index.js)
html
    head
        // the first `title` represents html's title tag
        // the second `title` represents the variable named `title` to be passed in
        title= title
    body
        h1= message
```
  
```html
<!-- When the above example printed on website, we get the source code as below -->
<html>
    <head>
        <title>My Express App</title>
    </head>
    <body>
        <h1>Hello</h1>
    </body>
</html>
```
  
> Structure the NodeJS App
* <a href="https://github.com/DylanLin29/Notes/tree/master/Web%20Development/NodeJS/structure_express_app">separating different routes into different files</a>
  
<br>
  
  
###  2. Difference between `Synchronous Code` and `Asynchronous Code`
  
------------------------------------------------
`Synchronous Code:`
```Javascript
// Only after the first line is executed, 
// the second line can be executed
console.log('Before');
console.log('After');
```
``` Javascript
// Console:
Before
After
```
----------------------------------
`Asynchronous Code:`
* not multi threads or concurrently
* single thread
```Javascript
// setTimeout is an asynchronous function
console.log('Before');
setTimeout(() => {
    console.log('Reading a user from a database');
}, 2000);
console.log('After');
```
> After the first line is executed, go to the second line. 
While waiting for 2 seconds, go to the third line. After the third line is executed, execute the second line once 2 seconds have passed.
```C++
// Console:
Before
After
Reading a user from a database
```
  
###  3. Dealing with `Asynchronous Code`:
  
----------------------------------------
1. `Callbacks`
2. `Promises`
3. `Async/await`
  
Example.
```Javascript
console.log('Before');
const user = getUser(1);
console.log(user);
console.log('After');
  
function getUser(id) {
    setTimeout(() => {
        console.log('Reading a user from a database...');
        return {id: id};
    }, 2000);
}
```
> 1. Execute the first line (`Before`)
> 2. Excute the function (return value is not available by the time of calling the function, so it's undefined)
> 3. Execute the forth line (`After`)
> 4. After the 2-second countdown (`Reading a user from a database...`)
```C++
// console
Before
undefined
After
Reading a user from a database...
```
---------------------------------
1. `Callbacks`
Solve example above
```Javascript
console.log('Before');
getUser(1, (user) => {
    console.log('User', user)
});
console.log('After');
  
function getUser(id, callback) {
    setTimeout(() => {
        console.log('Reading a user from a database...');
        callback({ id: id});
    }, 2000);
}
```
  
```Javascript
// console:
Before
After
Reading a user from a database
User {id: id}
```
  
2nd Example (double callback)
```Javascript
console.log('Before');
getUser(1, (user) => {
    console.log(user);
    getRepos(user.githubId, (repos) => {
        console.log(repos);
    });
});
console.log('After');
  
function getUser(id, callback) {
    setTimeout(() => {
        console.log('Reading a user from a database...');
        callback({ id: id, githubId: 'Dylan'};
    }, 2000);
}
  
function getRepos(username, callback) {
    setTimeout(() => {
        console.log('Calling Github API...');
        callback(['repo1', 'repo2']);
    }, 2000);
}
```
```C++
// Console
Before
After
Reading a user from a database...
{ id: 1, githubId: 'Dylan' }
Calling Github API...
[ 'repo1', 'repo2' ]
```
  
`Named function` to solve `nested callback`:
* in order to make nested callbacks look better
```Javascript
console.log('Before');
getUser(1, getReposAndUser);
console.log('After');
  
function getReposAndUser(user) {
    console.log(user);
    getRepos(user.githubId, displayRepos)
}
  
function displayRepos(repos) {
    console.log(repos);
}
  
function getUser(id, callback) {
    setTimeout(() => {
        console.log('Reading a user from a database...');
        callback({ id: id, githubId: 'Dylan'});
    }, 1000);
}
  
function getRepos(username, callback) {
    setTimeout(() => {
        console.log('Calling Github API...');
        callback(['repo1', 'repo2']);
    }, 1000);
}
```
-----------------------------------
2. `Promises`
* Promises holds the eventual result of an asynchronous operation
* Promises initial with pending state, then go to the result state or reject state.
  
```Javascript
const p = new Promise((resolve, reject) => {
    // async work
    setTimeout(() => {
        // resolve(1);
        reject(new Error('something went wrong...'));
    }, 1000);
});
  
p
    .then(result => console.log('Result:', result)) // get the result
    .catch(err => console.log('Error:', err.message)); // catch the error
```
  
```Javascript
// Console:
Error: something went wrong
```
  
```Javascript
const p = new Promise((resolve, reject) => {
    // async work
    setTimeout(() => {
        resolve(1);
        // reject(new Error('something went wrong...'));
    }, 1000);
});
  
p
    .then(result => console.log('Result:', result)) // get the result
    .catch(err => console.log('Error:', err.message)); // catch the error
```
```Javascript
// Console:
Result: 1
```
  
* Convert from `callback` to `promises`
```Javascript
// Callback
console.log('Before');
getUser(1, getReposAndUser);
console.log('After');
  
function getReposAndUser(user) {
    getRepos(user.githubId, displayRepos)
}
  
function displayRepos(repos) {
    console.log(repos);
}
  
function getUser(id, callback) {
    setTimeout(() => {
        console.log('Reading a user from a database...');
        callback({ id: id, githubId: 'Dylan'});
    }, 1000);
}
  
function getRepos(username, callback) {
    setTimeout(() => {
        console.log('Calling Github API...');
        callback(['repo1', 'repo2']);
    }, 1000);
}
```
  
```Javascript
// Promises
console.log('Before');
getUser(1)
    .then(user => getRepos(user.githubId))
    .then(result => console.log(result));
console.log('After');
  
function getUser(id) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Reading a user from a database...');
            resolve({ id: id, githubId: 'Dylan'});
        }, 1000);
    });
}
  
function getRepos(username) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Calling Github API...');
            resolve(['repo1', 'repo2']);
        }, 1000);
    });
}
```
  
* Parallel Promises:
* (Not concurrent nor multiple threads)
> Promise.all
```Javascript
// Promise.all example 1
const p1 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 1...');
        resolve(1);
    }, 2000);
});
  
const p2 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 2...');
        resolve(2);
    }, 2000);
});
  
Promise.all([p1, p2])
    .then(result => console.log(result));
```
  
```Javascript
// Pramise.all example 1 result
// The following lines almost appear at the same time
Async operation 1...
Async operation 2...
[ 1, 2 ]
```
  
```Javascript
// Promise.all example 2
const p1 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 1...');
        resolve(1);
    }, 2000);
});
  
const p2 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 2...');
        resolve(2);
    }, 1000);
});
  
Promise.all([p1, p2])
    .then(result => console.log(result));
```
  
```Javascript
// Promise.all example 2 result
// The first line appears after 1 second and the second line appears after another second
Async operation 2...
Async operation 1...
[ 1, 2 ]
```
  
```Javascript
// Promise.all example 3
const p1 = new Promise((resolve, reject) => {
    setTimeout(() => {
        console.log('Async operation 1...');
        reject('Something went wrong');
    }, 2000);
});
  
const p2 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 2...');
        resolve(2);
    }, 1000);
});
  
Promise.all([p1, p2])
    .then(result => console.log(result))
    .catch(error => console.log(error));
```
  
```Javascript
// Promise.all example 3 result
// As long as one async operation is rejected, only get the error message since all the async operations are binded together
Async operation 2...
Async operation 1...
Something went wrong
```
  
> Promise.race
  
```Javascript
// Promise.race example 1
const p1 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 1...');
        resolve(1);
    }, 2000);
});
  
const p2 = new Promise((resolve) => {
    setTimeout(() => {
        console.log('Async operation 2...');
        resolve(2);
    }, 1000);
});
  
Promise.race([p1, p2])
    .then(result => console.log(result));
```
  
```Javascript
// Promise.race example 2 result
// Only get the first fulfilled Async function (either reject or resolve)
Async operation 2...
2
Async operation 1...
```
  
------------------------
3. `Async and Await`
* In order to use the `async and await` method, we need to convert the `callback` function to `Promise` first
* Convert the `Promise` approach to `Async and Await` method
  
```Javascript
// Promise method
console.log('Before');
getUser(1)
    .then(user => getRepos(user.githubId))
    .then(result => console.log(result));
console.log('After');
  
function getUser(id) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Reading a user from a database...');
            resolve({ id: id, githubId: 'Dylan'});
        }, 1000);
    });
}
  
function getRepos(username) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Calling Github API...');
            resolve(['repo1', 'repo2']);
        }, 1000);
    });
}
```
  
```Javascript
// Async and await method
console.log('Before');
// The await function only works in an async function
async function displayRepos() {
    // we have to use the try catch block to catch the errors
    try {
        const user = await getUser(1);
        const repos = await getRepos(user.githubId);
        console.log(repos);
    } catch(err) {
        console.log('Error', err.message);
    }
}
displayRepos();
console.log('After');
  
  
function getUser(id) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Reading a user from a database...');
            resolve({ id: id, githubId: 'Dylan'});
        }, 1000);
    });
}
  
function getRepos(username) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log('Calling Github API...');
            resolve(['repo1', 'repo2']);
        }, 1000);
    });
}
```
  
###  3. Database `MongoDB`:
  
--------------------------
3.1 `Mongoose`:
* Connect `mongoose` to `mongodb`:
```Javascript
const mongoose = require('mongoose');
  
mongoose.connect('mongodb://localhost/playground', {
    useNewUrlParser: true,
    useUnifiedTopology: true
})
// since mongoose.connect returns a promise, we can use then and catch
    .then(() => console.log('Connected to MongoDB...'))
    .catch(err => console.log('Could not connect to MongoDB...', err));
```
> In order to successfully connect with local MongoDB, we need to start the MongoDB server before running the code above<br> 
(current user is `dylan`)<br>
`mkdir -p /Users/dylan/data/db`(only the first time)<br>
`mongod --dbpath=/Users/dylan/data/db`
* Schema: <br>
type: `String`, `Number`, `Date`, `Buffer`(use to store binary data), `Boolean`, `ObjectID`(unique identifier), `Array`
  
<br>
<b>create a CourseSchema and save the data</b>
<br>
Example: 
  
```Javascript
const courseSchema = new mongoose.Schema({
    name: String,
    author: String,
    tags: [ String ],
    date: { type: Date, default: Date.now },
    isPublished: Boolean
});
// create the model class of the schema
const Course = mongoose.model('Course', courseSchema);
  
// the await method has to be wrapped inside the async function
async function createCourse() {
    // create an instance of the class above
    const course = new Course({
        name: 'Angular',
        author: 'Dylan',
        tags: ['angular', 'frontend'],
        isPublished: true
    });
  
    // async operation (return a promise)
    // save the info in the mongodb database using the save method
    const result = await course.save();
    console.log(result);
}
  
createCourse();
```
<br>
  
<b>query data</b><br>
  
Example: 
```Javascript
// Course is the created mongoose model above
async function getCourse() {
    const courses = await Course
        .find({ author: 'Dylan', name: 'Node.js' }) // nothing is specified, get everything from Course
        // below are optional
        .limit(10)
        .sort({ name: 1}) // sort by name, 1 indicates ascending order (a-z), -1 indicates decending order
        .select({ name: 1, tags: 1 }) // indicate that we only want to get the name and tags properties
    console.log(courses);
}
```
> Some query operators
```Javascript
// eq (equal)
// ne (not equal)
// gt (greater than)
// gte (greater than or equal to)
// lt (less than)
// lte (less than or equal to)
// in
// nin (not in)
async function getCourses() {
    const courses = await Course
        // .find({ price: {$in [10, 15, 20]}})
        .find({ price: {$gte: 10, $lte: 20 }}) // courses less than or equal to 20 and greater than 10
}
```
  
> count: return the number of documents that satisfy the query
```Javascript
async function getCourses() {
    const courses = await Course
        .find()
        count()
}
```
```Javascript
// Console
Connected to MongoDB...
2 // 2 of the documents satisfy the query
```
  
> Pagination: get all the documents of a page
```Javascript
async function getCourses() {
    // assume we want the document at page 2
    const pageNumber = 2;
    const pageSize = 10;
  
    const courses = await Course
        .find()
        // Use the code below to get the courses at the desired page
        .skip((pageNumber - 1) * pageSize)
        .limit(pageSize)
}
```
  
> Some logical query operators
```Javascript
// or
// and
async function getCourses() {
    const courses = await Course
        .find()
        .or([{author: 'Dylan'}, {isPublished: true}]); // return all the courses that either author is 'Dylan' or isPublished
}
```
  
> Some query operators with regular expression
```Javascript
async function getCourses() {
    const courses = await Course
        // /.../ indicates regular expression
        // /^.../ indicates all the string starts with ...
        .find({ author: /^Dylan/})
  
        // /...$/ indicates all the string ends with ...
        .find({ author: /Dylan$/})
  
        // i indicates case insensitive
        .find({ author: /Dylan$/i})
  
        // /.*Dylan.*/ means contains Dylan
        .find({ author: /.*Dylan.*/})
}
  
async function getCourses() {
    const courses = await Course
  
}
```
(Check the tutorials of regular expressions to get more information)
  
<br>
<b>Update data</b>
<br>
  
* Method 1: query first, findById(), Modify its properties, and then save()
  
Example: 
```Javascript
async function updateCourse(id) {
    // Course.findById returns a promise
    const course = await Course.findById(id);
    // When the course is not found in the database, return
    if (!course) {
        return;
    }
    // Example updates: 
    course.author = 'Another author';
    // Another way of updating the data:
    course.set({
        isPublished: true,
        author: 'Another Author'
    });
  
    // result is the updated version of the course
    const result = await course.save();
}
  
updateCourse(someID);
```
  
* Method 2: update the data directly
  
Example:
```Javascript
async function updateCourse(id) {
    // retrieve every course from the database whose `isPublished` field is `false`
    // use mongodb update operator `$set`
    const result = await Course.update({isPublished: false}, {
        // there are more mongodb operators on `https://docs.mongodb.com/manual/reference/operator/update/`
        // here is an example of using $set as the operator
        $set: {
            author: 'Dylan',
            isPublished: true
        }
    });
  
    // another way of updating the course by id
    await Course.update({_id: id}, {
        $set: {
            author: 'Dylan'
        }
    })
    console.log(result) // {n: 1, nModified: 1, ok: 1} indicates how many datas are modified
  
  
    // if we don't want to retrieve the results as above
    // instead, we want to retrieve the courses
    const course = await Course.findByIdAndUpdate(id, {
        $set: {
            author: 'Dylan'
        }
    // to get the updated data, include {new: true}
    // if not, the return course is the previous versions
    }, {new: true})
}
```
  
<br>
<b>Remove data</b>
<br>
  
```Javascript
// Remove data example
async function removeCourse(id) {
    const result = await Course.deleteOne({ _id: id });
    console.log(result); // shows number of documents is deleted
  
    // delete the first one that satisfy the requirements
    await Course.deleteOne({ isPublished: true });
  
    // delete every document that satisfy the requirements
    const resultMany = await Course.deleteMany({ isPublished: true });
    console.log(resultMany); // shows number of documents is deleted
  
    const course = await Course.findByIdAndDelete(id);
    console.log(course); // get the deleted course document
}
```
  
###  4. Authentication and Autherization:
  
----------------------------------------
> Store password
* Hashing library: `npm install bcrypt`
    ```Javascript
        // Example of hashing the password
  
        const bcrypt = require('bcrypt');
        // we need to generate the salt before hashing
        // create the salt for 10 rounds this time
        const salt = await bcrypt.genSalt(10);
        cosnt newPassword = await bcrypt.hash(password, salt);
    ```
    ```Javascript
        // Example of comparing the hashed password with the entered password
        const bcrypt = require('bcrypt');
        // validatePassword is either true or false
        // hashed_password is usually from the database
        const validPassword = await bcrypt.compare(entered_password, hashded_password);
    ```
* Json Web Token
  