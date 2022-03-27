## Introduction to Data Engineering  

### 1. Introduction to Data Engineering 
<br>

#### 1. What is data engineering?  

<br>

> Data engineers: making your life easier

* Gather data from different sources
* Optimized database for analyses
* Removed corrupt data

Data scientist'slife go way easier!

>Definition of the job
An engineer that deveops, constructs, tests, and maintains archetectures such as databases and large-scale proessing systems

Now, they also require
* process large amounts of data
* Use of clusters of machines

>Data Engineer
* Develop scalable data architecture
* Streamline data acquisition
* Set up processes to bring together data
* Clean corrupt data
* Well versed in cloud technology
* The data engineer should make sure there's a separate database for analytics.
* find data from various sources, process it, or cleans it and finally loads it into an analytical database


>Data Scientist
* Mining data for patterns
* Statistical modeling
* Predictive models using machine learning
* Monitor business processes
* Clean outliers in data.

#### 2. Tools of the data engineers  
>Databases
* Hold large amounts of data
* Support application
* Other databases are used for analyses

>Processing
* clean
* Aggregate 
* Join

>Processing: an example

```Python
df = spark.read.parquet("users.parquet")

outliers = df.filter(df["age"] > 100)

print(outliers.count())
```

Data engineer understands the abstractions


>Scheduling 
* Plan jobs with specific intervals
* Resolve dependency requirements of jobs
* For example, `JoinProductOrder` needs to run after `CleanProduct` and `CleanOrder`

> Existing tools

Database: 
* MySQL
* PostgreSQL

Processing:
* Spark
* HIVE

Scheduling:
* Apache Airfow
* oozie
* 企鹅

> A data pipeline 

![standard graph](/Users/shayne_lin/Desktop/work experiennce/面试/Big Data Hadoop/截屏2022-03-27 下午1.11.09)

            