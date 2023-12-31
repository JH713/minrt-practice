#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef int t_bool;
# define FALSE 0
# define TRUE 1
typedef int t_object_type;
#define SP 0
#define LIGHT_POINT 1

#define EPSILON 1e-6

typedef struct s_vec3
{
	double x;
	double y;
	double z;
} t_vec3;

typedef t_vec3 t_point3;
typedef t_vec3 t_color3;

typedef struct s_ray
{
	t_point3 orig;
	t_vec3 dir;
} t_ray;

typedef struct s_camera
{
	t_point3 orig;
	double viewport_h;
	double viewport_w;
	t_vec3 horizontal;
	t_vec3 vertical;
	double focal_len;
	t_point3 left_bottom;
} t_camera;

typedef struct s_canvas
{
	int width;
	int height;
	double aspect_ratio;
} t_canvas;

typedef struct s_scene
{
	t_canvas canvas;
	t_camera camera;
	t_object *world;
	t_object *light;
	t_color3 ambient;
	t_ray ray;
	t_hit_record rec;
} t_scene;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;	
} t_sphere;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
} t_hit_record;

typedef struct s_object
{
	t_object_type type;
	void *element;
	void *next;
	t_color3 albedo;
} t_object;

typedef struct s_light
{
	t_point3 origin;
	t_color3 light_color;
	double bright_ratio;
} t_light;

#endif