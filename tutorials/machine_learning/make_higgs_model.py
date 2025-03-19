import tensorflow
from tensorflow.keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.layers import Input, Dense

model = Sequential() 
model.add(Dense(64, activation='relu',input_dim=7))
model.add(Dense(64, activation='relu'))
model.add(Dense(64, activation='relu'))
model.add(Dense(64, activation='relu'))
model.add(Dense(2, activation='sigmoid'))
model.compile(loss = 'binary_crossentropy', optimizer = Adam(learning_rate = 0.001), weighted_metrics = ['accuracy'])
model.save('Higgs_model.h5')
model.summary()
