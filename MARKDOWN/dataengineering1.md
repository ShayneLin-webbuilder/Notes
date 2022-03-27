## What is Data Engineering  


------------------------
### Chapter 1 - Introduction 
<br>

#### 1. Order the four steps of data science workflow. 

Data collection and storage.  
Data preparation  
Exploration and visualization  
Experimentation and prediction  

#### 2. Identify data engineers responsibilities  
Hint: Data engineers ensurethat the data is collected, stored and usable.   

> Data engineering tasks: 
* gathering consumption data
* ensuring corrupted, unreadable music tracks are removed and don't end up forcing customers.  
* Optimizing the customers databases for analysis.  

> Not Data engineering tasks:  
* Running on experiement to identify the optimal serach bar positioning in the app.  
* Building a visualization to understand listening patterns by city.  
* Based on their listening behavior predict which songs customers are likely to enjoy.  

#### 3. Big Data's 5Vs 

Value refers to how actionable the data is  
Data types refer to the variety of the data  
Veracity refers to how trustworthy the sources are  
Variety refers to type and nature of the data  
Velocity means how fast the data is generated and processed  

#### 4. Data engineers vs. data scientist  

Data engineer: ingest and store data;Set up databases;Build data pipelines. Software experts, software-oriented Python or Java, and SQL to create, update and transform databases.

Data scientist: exploit databases,access databases, use pipeline outputs. They prepare data according their analysis needs, explore it, build insightful visualizations, and run experiements or build predictive models. Analytics experts, analytics-oriented Python or R, and SQL to query, or request information from databases.  

#### 5. The data pipeline 

Company ingest data from many different sources, process, store, and this is why we need "pipeline", to automate from one station to the next to provide up-to-date, accurate, relevant data.   

In summary, data pipelines ensure an effcient flow of the data. Including:  
> Automate  
* Extracting   
* Transforming  
* Combining  
* Validating  
* Loading  

> Reduce  
* Human intervention  
* Errors  
* Time it takes data to flow  

<br>


#### 6. ETL& Data Pipelines)   
ETL stands for Extract transform, load and is a popular framework for designing data pipelines. However, data pipelines do not necessarily include a transformation step.  

> ETL  
* Popular framework for designing data pipelines
    * Extract data
    * Transform extracted data  
    * Load transformed data to another database  
    * Data is processed here before it is stored.  

> Data pipelines.  
* Move data from one system to another  
* May follow ETL but not all the time.
* Data may not be transformed  
* Directly load data in applications.

> Weekly playlist's Project for spotflix  
1. Extract the songs Julian listened to the most over the past month  
2. Find other users who listened to these same songs a lot as well  
3. Load only the 10 top songs these users listened to the most over the past week into a table called similar profiles  
4. Extract only songs these other users listened to that one of the same genre as the one in Julian's listening sessions. These are our recommendations.
5. Load the recommended songs into a new table. That's Julian's weekly playlists. 


### Chapter 2 - Storing Data  

#### 1. Data structures  
> Structured data requirements
* Easy to search and organize
* consistent model, rows , and columns
* Defined types 
* can be grouped to form relations
* stored in relational databases
* about 20% of the data is structured
* created and queries using SQL.

> Semi-structured data 
* Relatively easy to search and organize
* Consistent model, less-rigid implementation: different observations have different sizes
* Different types 
* can be grouped, but needs more work.
* Have more freedom 
* No SQL databases such as JSON, XML, YAML file formats.

```
// JSON file example
{
    {"user_1511:  
        "last_name": "Lacroix",  
        "first_name: "Hardrien"  
        "favorite_artists":["taylor","billie"]},
    {"another user" }
}
```
For example, if you have more favorite artists than others, semi-structured files are easier than relational database. Therefore, it is more flexible.  

> Unstructured data  

* Does not follow a model, can't be contained in rows and columns
* Difficult to search and organize.
* Texts, sound, pictures or videos
* Usually stored in data lakes, can appear in data warehouses or databases.
* Most of the data is unstructured
* Can be extremely valuable
* Could be extracted with the advent of machine learning and artificial intelligence.
* To add information to unstructed data, we will add information to make it semi-structured. 

#### 2. SQL  

> SQL  
* Structured Query Language  
* Industry standard for Relational Database Management System (RDBMS)
* Allows you to access many records at once, and group, filter or aggregate them
* Close to written English, easy to write and understand
* Data engineers use SQL to create and maintain databases

> Data engineers and data scientists in SQL  

Date engineers create, delete, update, modifying table, while data scientist only querying query.



### Data warehouses and data lakes  

> Data lake  

* Stores all the raw data, it's relatively 
* Can be petabytes (1 million GBs)
* Stores all data structres: structured, semi-structured, unstructured.
* Cost-effective because it does not enforce any model on the way to store the data.
* Difficult to analyze.
* Requires an up-to-date data catalog
* USed by data scientists for real-time analytics

> Data warehouse  
* Specific data for specific use  
* Relatively small
* Stores mainly structured data
* Optimized for data analysis
* Ad-hoc, read-only queries.  

> Data catalog for data lakes  
  
A data catalog is a source of truth that compensates for the lack of structure in a data lake.

* What is the source of this data?
* Where is this data used?
* Who is the owner of the data?
* How often is this data updated?
* Good practice in terms of data governance
* Ensures reproductivity for future use if anything happened. Or, if someone wants to reproduce an analysis from the very beginning, starting with the ingestion of the data.
* No catalog -> data swamp
* Good practice for any data storage solution
    * Reliability
    * Autonomy
    * Scalability  

We can go from finding data to preparing it without having to rely on a human source of information everytime. 
 
> Database vs. data warehouse
* Loosely defined as organized data stored and accessed on a computer
* Data warehouse is a type of database.

## 3. Moving and processing data

### 1. Processing data  
> Data processing definition

converting <b>raw data</b> into <b>meaningful</b> information.

> Data processing value

<b>Conceptually</b>
* Remove unwanted data
* Optimize memory, process and network costs because storing and processing data is not free.
* Convert data from one type to another
* Organize data
* To fit in a schema/structure
* Increase productivity by automating it and creating data pipelines.

<b>At Spotiflix</b>
* No long term need for testing feature data
* Can't afford to store and stream files this big when uncompressed all data. 
* Convert songs from .flac to .ogg
* Reorganize data from the data lake to data warehouses
* Employee table examle: separting name and last name, using logic instead of text to distinguish between part-time and full-time employees.
* Enables data scientists.

> How data engineers process data  
<b>Conceptually</b>
* Data manipulation, cleaning and tidying tasks.
    * That can be automated
    * That will always need to be done.
* Store data in a sanely structured database
* Create view on top of the database tables for easy access by analysts. Views are the output of a stored query on the data.
* Optimizing the performance of the database like apache spark here. 

<b>Spotflix</b>
* Rejecting corrupt song files
* Deciding what happens with missing metadata. (Do we leave the genre blank, or do we provide one by default)
* Separate artists and albums tables...
* but provide new combining them for analytics
* Indexing the data with hadoop/ apache spark.

### 2. Connect the dots  
Divide actions to "Extract, Transform, or Load"  

> Extract  

Getting data simily and not modifying anything.  

> Transform  

Sorting, modifying, summerizing. 

> Load  

Saving information. Inputing information.

> What data proccessing really need?

most of the data processing steps are transformation steps including selecting, encoding, calculating new values, sorting and ordering, joining data from multiple sources, aggregating, pivoting tables, splitting one table into several ones, removing duplicate values.

> Validating data  

It can be extract (you don't extract if it's not necessary) or transform (you check that your results make sense before saving them.)

### 3. Scheduling Data Introduction  

> Scheduling  
* Can apply to any task listed in data processing.
* Scheduling is the glue of your system
* Holds each piece and organize how they work together
* Runs tasks in a specific order and resolve all dependencies.

> Manual, time and sensor scheduling  

* Automation means that we want to perform specific tasks in automatically in terms of time and conditions. Most time, we'd prefer automation than manual. 

* <b>Manual scheduling</b>: update the employee table manually.
* <b>Time scheduling</b>: automaticlly run at a specific time, update the employee table at 6 AM
* <b>Sensor scheduling</b>: Automatically run if a specific condition is met. We could update the departments table only if a new employee was added to the employees table.

>Batches (一批) and streams (一系列)  

* Batches
    * Data can be ingested in batches, which means they are grouped by group records at intervals.
    * Often cheaper
    * For example, songs uploaded by artists in every 10 minutes, employee table will update overnight.
    * Offline listening is saved through batch of saved songs.
    * Processed at intervals and records are grouped

* Streams
    * Send individual records right away.
    * For example, new users signing in
    * On line listening without saving, is called streaming 
    * sent individually right away

* Real time?
    * Fraud detection

> Scheduling tools   

Apache Airflow, or Luigi.

### 4. Schedules examples  

* Manual:
    * Running the song encoding pipeline, because engineering changed the encoder and wants to make sure they stil pass the validation check.  
    * Running the pipeline processing sign ups because in the past 10 minutes, 100 new users complainted to support that they cant connect

* Time:  
    * Processing music videos uploaded by artists every hour.
    * Generating the spotiflix weekly playlist from Chapter 1 every monday at 00:00 AM
    * Collecting data from Google Analytics every morning to check how the promotion campaign is going.  

* Condition: 
    * Running validation checks if new videos are being collectd.
    * Updating the number of followers in a playlist table after a user subscribed to it.

### 5. Parallel computing 
> Basics of parallel computing 
* Basics of modern data processing tools.
* Necessary:  
    * Mainly because of memory
    * Also for processing power.
* How it works:
    * Split tasks up into several smaller subtasks
    * Distribute these subtasks over several computers.

> Benefits and risks of parallel computing  

* Advantages
    * Extra processing power
    * Reduced memory footprint, can partition the data and load the subsets into memory of different computers.  

* Disadvantages  
    * Moving data incurs a cost. Requires some communication between processes, takes some additional time.
    * Communication time in reduce procedure.  

### 6. Cloud computing  

> Cloud computing for data processing  

<b>Servers on premises</b>
* Bought
* Need space
* Electrical and maintenance cost
* Enough power for peak moments
* Processing power unused at quieter times.

<b>Servers on the cloud</b>

* Rented cheap
* don't need space
* Use just the resources we need
* when we need them
* the closer to the user the better

> Cloud computing for data storage  
* Database reliability: data replication for different geographical location.
* Risk with sensitive data

In america, cloud computing providers are separated in tasks: file storage, computation, and databases.  

> Multicloud

<b>Definition:</b> you use different providers' cloud computing in terms of storage, computing and databases.

<b>Benefits</b> 
* reduce reliance on a single vendor
* Cost-effectiveness
* Local laws requiring certain data to be physically present within country.
* Millitating against disasters

<b>Disadvantages</b>
* Cloud providers try to lock in consumers
* Incompatibility
* security and governmence.