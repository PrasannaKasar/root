import tensorflow
from tensorflow.keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.layers import Input, Dense, Dropout, Flatten, Conv2D, MaxPooling2D, Reshape, BatchNormalization

model = Sequential() 
model.add(Reshape((16, 16, 1), input_shape = (256, )))
model.add(Conv2D(10, kernel_size = (3, 3), kernel_initializer = 'glorot_normal',activation = 'relu', padding = 'same'))
model.add(BatchNormalization())
model.add(Conv2D(10, kernel_size = (3, 3), kernel_initializer = 'glorot_normal',activation = 'relu', padding = 'same'))
model.add(MaxPooling2D(pool_size = (2, 2), strides = (1,1))) 
model.add(Flatten())
model.add(Dense(256, activation = 'relu')) 
model.add(Dense(2, activation = 'sigmoid')) 
model.compile(loss = 'binary_crossentropy', optimizer = Adam(learning_rate = 0.001), weighted_metrics = ['accuracy'])
model.save('model_cnn.h5')
model.summary()
