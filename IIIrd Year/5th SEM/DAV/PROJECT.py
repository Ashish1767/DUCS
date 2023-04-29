
from ast import increment_lineno
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

import panel as pn
pn.extension('tabulator')
import hvplot.pandas
get_ipython().run_line_magic('matplotlib', 'inline')


# In[2]:


sns.set_style("darkgrid")
plt.rcParams['font.size']=15
plt.rcParams['figure.figsize']=(10,7)
plt.rcParams['figure.facecolor']='#FFE5B4'


# In[3]:


data=pd.read_csv("World-Happiness-Report-2022.csv")

data.head()


# In[4]:


data_columns = ["Country name","Regional indicator","Ladder score", "Logged GDP per capita","Social support","Healthy life expectancy","Freedom to make life choices","Generosity","Perceptions of corruption"]


# In[5]:


data = data[data_columns].copy()


# In[6]:


happy_df = data.rename( columns = {'Country name':'country_name','Regional indicator':'regional_indicator','Ladder score':'happiness_score', 'Logged GDP per capita':'logged_GDP_per_capita','Social support':'social_support','Healthy life expectancy':'healthy_life_expectancy','Freedom to make life choices':'freedom_to_make_life_choices','Generosity':'generosity','Perceptions of corruption':'perceptions_of_corruption'})


# In[ ]:





# In[7]:


happy_df.head()


# In[8]:


happy_df.isnull().sum()


# In[9]:


#plot b/w Happiness And GDP

plt.rcParams['figure.figsize']=(15,7)
plt.title('Plot Between Happiness Score And GDP')
sns.scatterplot(x = happy_df.happiness_score, y = happy_df.logged_GDP_per_capita, hue = happy_df.regional_indicator, s = 200);

plt.legend (loc = 'upper left', fontsize = '10')
plt.xlabel("Happiness Score")
plt.ylabel("GDP Per Capita")


# In[10]:


gdp_region = happy_df.groupby('regional_indicator')['logged_GDP_per_capita'].sum()
gdp_region


# In[11]:


gdp_region.plot.pie(autopct = '%1.1f%%')
plt.title("GDP BY Region")
plt.ylabel('')


# In[12]:


#Total Countries

total_country = happy_df.groupby('regional_indicator')[['country_name']].count()
print(total_country)


# In[24]:


#Correlation Map

cor = happy_df.corr(method = 'pearson')
f, ax = plt.subplots(figsize = (10,5))
sns.heatmap(cor,mask = np.zeros_like(cor, dtype=np.bool_),
           cmap='Blues',square=True, ax=ax)


# In[14]:


# Corruption in Regions

corruption = happy_df.groupby('regional_indicator')[['perceptions_of_corruption']].mean()
corruption


# In[15]:


plt.rcParams['figure.figsize']=(12,8)
plt.title('Perception of Corruption in Various Regions')
plt.xlabel("Regions",fontsize = 15 )
plt.ylabel("Corruption Index",fontsize = 15)
plt.xticks(rotation = 40 , ha='right')
plt.bar(corruption.index, corruption.perceptions_of_corruption)


# In[16]:


top_10 = happy_df.head(10)
bottom_10 = happy_df.tail(10)


# In[17]:


fig , axes = plt.subplots(1,2, figsize=(16,6))
plt.tight_layout(pad = 2)

# Top 10

xlabels = top_10.country_name
axes[0].set_title("Top 10 Happiest Countries Life Expectancy")
axes[0].set_xticklabels(xlabels , rotation = 45 , ha='right')
sns.barplot(x = top_10.country_name , y = top_10.healthy_life_expectancy, ax = axes[0])
axes[0].set_xlabel('Country Name')
axes[0].set_ylabel('Life Expectancy')


# Bottom 10

xlabels = bottom_10.country_name
axes[1].set_title("bottom 10 Happy Countries Life Expectancy")
axes[1].set_xticklabels(xlabels , rotation = 45 , ha='right')
sns.barplot(x = bottom_10.country_name , y = bottom_10.healthy_life_expectancy, ax = axes[1])
axes[1].set_xlabel('Country Name')
axes[1].set_ylabel('Life Expectancy')


# In[18]:


plt.rcParams['figure.figsize']=(15,7)
sns.scatterplot(x = happy_df.freedom_to_make_life_choices, y=happy_df.happiness_score , hue = happy_df.regional_indicator , s = 200)
plt.legend(loc = 'upper left', fontsize = 12)
plt.xlabel('Freedom to Make Life Choices')
plt.ylabel('Happiness Score')


# In[19]:


country = happy_df.sort_values(by = 'perceptions_of_corruption').head(10)
plt.rcParams['figure.figsize'] = (12,6)
plt.title('Countries With Most Perception of Corruption')
plt.xlabel('Country', fontsize = 13)
plt.ylabel('Courruption Index', fontsize = 13)
plt.xticks(rotation = 30, ha='right')
plt.bar(country.country_name, country.perceptions_of_corruption)


# In[20]:


country = happy_df.sort_values(by = 'perceptions_of_corruption').tail(10)
plt.rcParams['figure.figsize'] = (12,6)
plt.title('Countries With Most Perception of Corruption')
plt.xlabel('Country', fontsize = 13)
plt.ylabel('Courruption Index', fontsize = 13)
plt.xticks(rotation = 30, ha='right')
plt.bar(country.country_name, country.perceptions_of_corruption)


# In[21]:


# Corruption vs Happiness

plt.rcParams['figure.figsize']=(15,7)
sns.scatterplot(x = happy_df.happiness_score, y = happy_df.perceptions_of_corruption , hue = happy_df.regional_indicator, s = 200)
plt.legend(loc = 'lower left', fontsize = '14')
plt.xlabel('Happiness Score')
plt.ylabel('Corruption')

