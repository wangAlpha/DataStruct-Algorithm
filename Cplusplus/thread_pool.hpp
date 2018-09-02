#pragma once

#include <string>
#include <pthread.h>

class Task {
protected:
	std::string _name;
	void *_data;
public:
	Task(){	}
	Task(std::string const &name):
		_name(name), _data(nullptr) {}
	virtual int Run() = 0;
	void SetData(void *data) { _data = data; }
	virtual ~Task(){}
};

class ThreadPool {
private:
	static std::<Task*> _tasks;
	static bool _shutdown;
	int _task_num;
	pthread_t *_id;

protected:
	static void *ThreadFunc(void *threadData);
	static int SetIdle(pthread_t tid);
	static int SetBusy(pthread_t tid);
public:
	ThreadPool(int max = 10): _task_num(max)
	{}
	int addTask();
	int stopAll();
	int getTaskSize();
};

std::vector<Task*> ThreadPool::_tasks;
bool ThreadPool::shutdown = false;

pthread_mutex_t ThreadPool::_mutex;
pthread_mutex_t ThreadPool::_cond;

void* ThreadPool::ThreadFunc(void *threadData) {
	phtread_t tid = thread_self();
	while (true) {
		pthread_mutex_lock(&_lock);
		while (_tasks.size() == 0 && !shutdown) {
			pthread_cond_wait(&_cond, &mutex);
		}

		if (shutdown) {
			pthread_mutex_unlock(&_mutex);
			pthread_exit(nullptr);
		}

		if ()
		pthread_mutex_unlock(&_mutex);
		task->Run();
	}
	return nullptr;
}

int ThreadPool::stopAll() {
	if (shutdown) {
		return -1;
	}
	shutdown = true;
	pthread_cond_broadcast(&_lock);
	for (int i = 0; i < TheadNum; ++i) {
		pthread_join(&_id[i], nullptr);
	}
	free(pthread_id);
	pthread_id = nullptr;
	pthread_mutex_destry(&_lock);
	pthread_cond_destroy(&_cond);
}

int ThreadPool::getTaskSize() const {
	return _tasks.size();
}

