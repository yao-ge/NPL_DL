#!/usr/bin/env python3

import tensorflow as tf
import horovod.tensorflow as hvd
import time

# Initialize Horovod
hvd.init()

config = tf.ConfigProto(allow_soft_placement=True)
config.gpu_options.allow_growth = True
config.gpu_options.visible_device_list = str(hvd.local_rank())

# Rank
rank = hvd.rank()
#print( "rank = ", rank );
#times = 1025
times = 1
with tf.device('/cpu:0'):

  if rank == 0:
      #const = tf.constant([-0.0001,0.0001,0.00001,0.000001,0.0000001]*times)
      #const = tf.constant([-0.0001,-0.00001,-0.000001,-0.0000001]*times)
      #const = tf.constant([-0.0001]*times)
      #const = tf.constant([0.1]*times)
      const = tf.constant([1.,2.,3.,4.]*times)
      #const = tf.constant([-1.,-2.,-3.,-4.]*times)
      #const = tf.constant([1.]*times)
      #const = tf.constant([0,0,0,0]*times)
  else:
      #const = tf.constant([-0.0001,-0.00001,-0.000001,-0.0000001]*times)
      #const = tf.constant([0.0001,0.00001,0.000001,0.0000001]*times)
      #const = tf.constant([-0.001,0.001,0.0001,0.00001,0.000001]*times)
      #const = tf.constant([0.001]*times)
      #const = tf.constant([-0.1]*times)
      #const = tf.constant([-1.,-2.,-3.,-4.]*times)
      const = tf.constant([1.,2.,3.,4.]*times)
      #const = tf.constant([1.]*times)
      #const = tf.constant([0,0,0,0]*times)
  reduced = hvd.allreduce(const, average=False)
  
  # Constant tensor to reduce
  #const = tf.constant([0.0001,0.00001,0.000001,0.0000001,-0.00000001, 0.00000001,-0.000000001, 0.000000001, -0.00000000001,0.00000000001,-0.000000000001, 0.000000000001, 12, -12, -0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0]*times)
  #const = tf.constant([0.0001,0.00001,0.000001,0.0000001]*times)
  #const = tf.constant([1., 2.,3.,4.,5.,6.,7.,8.])
  #reduced = hvd.allreduce(const, average=False)
  #const = tf.constant([2., 2.,3.,4.,5.,6.,7.,8.]*times)
  #reduced = hvd.allreduce(const, average=False)
  #const = tf.constant([3, 2.,3.,4.,5.,6.,7.,8.]*times)
  #reduced = hvd.allreduce(const, average=False)
  #const = tf.constant([4., 2.,3.,4.,5.,6.,7.,8.]*times)
  #reduced = hvd.allreduce(const, average=False)
  #const = tf.constant([5., 2.,3.,4.,5.,6.,7.,8.]*times)
  #reduced = hvd.allreduce(const, average=False)
  #reduced = hvd.allreduce(reduced, average=False)
  #reduced /= 9.

# Monitored session
# hooks = [hvd.BroadcastGlobalVariablesHook(0)]
# sess = tf.train.MonitoredTrainingSession(config=config, hooks=hooks)
sess = tf.Session(config=config)
# I expect a summed tensor -> [2,4]
start =time.clock()
print("[Tensorflow Session] The allreduce output from member-%d is:" % rank, sess.run(reduced))
print()

