import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Activation
from tensorflow.keras.optimizers import Adam

# Create the model
model = Sequential()

# Add layers to the model
model.add(Dense(64, input_shape=(64,), activation='tanh'))
model.add(Dense(32, activation='sigmoid'))
model.add(Dense(16, activation='relu'))
model.add(Dense(8, activation='relu'))
model.add(Dense(4, activation='linear'))

# Compile the model
model.compile(loss='mean_absolute_error', optimizer=Adam(learning_rate=0.001))

# Generate some random training data
random_generator = np.random.RandomState(42)
x_train = random_generator.rand(4, 64)
y_train = random_generator.rand(4, 4)

# Train the model
model.fit(x_train, y_train, epochs=10, batch_size=4)

# Save the model
model.save('CustomKerasModel.h5')
