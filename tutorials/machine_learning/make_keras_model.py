import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'

import numpy as np
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Input,Dense,Activation,ReLU
from tensorflow.keras.optimizers import SGD

input=Input(shape=(64,),batch_size=4)
x=Dense(32)(input)
x=Activation('relu')(x)
x=Dense(16,activation='relu')(x)
x=Dense(8,activation='relu')(x)
x=Dense(4)(x)
output=ReLU()(x)
model=Model(inputs=input,outputs=output)

randomGenerator=np.random.RandomState(0)
x_train=randomGenerator.rand(4,64)
y_train=randomGenerator.rand(4,4)

model.compile(loss='mean_squared_error', optimizer=SGD(learning_rate=0.01))
model.fit(x_train, y_train, epochs=5, batch_size=4)
model.save('KerasModel.h5')

