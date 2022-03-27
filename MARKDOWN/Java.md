### 1. Functions
------------
* void is a reserve keyword. name() -> sendEmail()

```Javascript
* Void Name() {
    ...
}
```

* class to organize functions, it is a container for methods.

```Javascript
public class Main {
    public void main(String[] args){
        // it's a public function means that we can accessible from other part of this program.
        // the static method should always be with main method.
        // void means the function is not going to return any value.
        // we have only one parameter in this program, use the parameter to pass value to the program.
        System.out.println("Hello World");
        //System is a class,
        //out is a field
        //println is a member
        //execute with ctrl + R
    }
}
```

In Java, there's different conventionss to naming classes and methods. 

* Classes: we use <b>PascalNamingConvention</b> -> which means we use Capitalization for all of our words. 

* Methods: we use <b>camelNamingConvention</b>, which means every word to be capitalized except for the first letter.
### 2. First Program in Java
-------------------------

template on itellij IDEA

```javascript
package com.codewithshayne;
// package statement to specify which this class belongs to. ; to terminate with semicolum.

public class Main {

    public static void main(String[] args) {
	    System.out.println("Hello World");
            //System is a class,
            //out is a field
            //println is a member
            //execute with ctrl + R
    }
}
```

To run the program, go to terminal, direct to src -> file name -> compile it with java c - > cd .. -> cd .. -> go to src file -> then use java com.codewithmosh.Main

```
codewithmodsh $javac Main.java
codewithmosh $ls
Main.class     Main.java
codewithmosh $cd ..
com $cd ..
src $java com.codewithmosh.Main
Hello World
```

#### * Theories for Java Processing

The program processing is divided to two parts. Compilation and execution.
<b>Compilation</b>
<b>Execution</b>
source code (*.java) -> Java compiler -> Byte Code (*.class)
<b>Independence</b>
Java is independent of the system.
Byte Code -> Java Virtual Machine -> Native Code

### 3. <b>Basics of this course</b>
a. Fundamentals
* Types
* Control flow
* Clean coding
* Finding and fixing errors
* Packaging your applications  

<br>

* Variables and constants
* Primitive and Reference Types
* Casting
* Numbers,strings, and Arrays
* Read Input

b. Object-oriented Programming

c. Core Java APIs

d. Advanced Features
Databases





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

### 3. Node Package Manager
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

### 3. Restful APIs Using Express
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
* ![alt text](https://github.com/DylanLin29/Notes/blob/master/Web%20Development/Images/Postman%20example.png)
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
