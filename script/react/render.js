/**
 * 显示不显示东西
 */

function ShowSayHello(props) {
	if (!props.warn) return null
	return <h1>这个是一个警告 !</h1>
}
class ShowComponent extends React.Component {
	constructor(props) {
		super(props)
		this.state = {
			shows: true,
		}
		this.handleClick = this.handleClick.bind(this)
	}

	handleClick() {
		this.setState((prev) => ({ shows: !prev.shows }))
	}
	render() {
		return (
			<div>
				<ShowSayHello warn={this.state.shows} />
				<button onClick={this.handleClick}>
					{this.state.shows ? '显示' : '消失'}
				</button>
			</div>
		)
	}
}

/**
 * 挂载不挂载
 */
class Clock extends React.Component {
	constructor(props) {
		super(props)
		this.state = { date: new Date() }
		this.name = props.name
	}
	// 挂载
	componentDidMount() {
		this.timerID = setInterval(() => this.tick(), 1000)
	}

	// 卸载
	componentWillUnmount() {
		clearInterval(this.timerID)
	}
	// 挂载的时候设置的 数据
	tick() {
		this.setState({
			date: new Date(),
		})
	}
	render() {
		return (
			<div>
				<h1>Hello, world! {this.name} </h1>
				<h2>现在是 {this.state.date.toLocaleTimeString()}.</h2>
				<FormatedDtae date={this.state.date} />
			</div>
		)
	}
}
Clock.defaultProps = {
	name: 'default name ',
}

/**
 * list
 */
function NumberList(props) {
	const numbers = props.numbers
	const listItems = numbers.map((number) => (
		<li key={number.toString()}>{number}</li>
	))
	return <ul>{listItems}</ul>
}

/**
 *
 * 指定数组的key
 */
function ListItem(props) {
	// 对啦！这里不需要指定key:
	return <li>{props.value}</li>
}

function NumberList(props) {
	const numbers = props.numbers
	const listItems = numbers.map((number) => (
		// 又对啦！key应该在数组的上下文中被指定
		<ListItem key={number.toString()} value={number} />
	))
	return <ul>{listItems}</ul>
}

/**
 *  jquery send
 */
class UserGist extends React.Component {
	constructor(props) {
		super(props)
		this.state = { username: '', lastGistUrl: '' }
	}

	componentDidMount() {
		this.serverRequest = $.get(
			this.props.source,
			function (result) {
				var lastGist = result[0]
				this.setState({
					username: lastGist.owner.login,
					lastGistUrl: lastGist.html_url,
				})
			}.bind(this),
		)
	}

	componentWillUnmount() {
		this.serverRequest.abort()
	}

	render() {
		return (
			<div>
				{this.state.username} 用户最新的 Gist 共享地址：
				<a href={this.state.lastGistUrl}>{this.state.lastGistUrl}</a>
			</div>
		)
	}
}
// <UserGist source="https://api.github.com/users/octocat/gists" />,

/**
 * 父子组建传值
 */

class M1 extends React.Component {
	render() {
		return (
			<div>
				<input
					type="text"
					value={this.props.myData}
					onChange={this.props.handleChange}
				/>
				<h4>{this.props.myDataProp}</h4>
			</div>
		)
	}
}

class M2 extends React.Component {
	constructor(props) {
		super(props)
		this.handleChange = this.handleChange.bind(this)
		this.state = { value: 'hell0 M2' }
	}
	handleChange(event) {
		this.setState({
			value: event.target.value,
		})
	}
	render() {
		var value = this.state.value
		return (
			<div>
				<M1 myData={value} handleChange={this.handleChange}></M1>
				<h4> {value}</h4>
			</div>
		)
	}
}

/**
 *  获取焦点
 */
class MyComponent extends React.Component {
	handleClick() {
		// 使用原生的 DOM API 获取焦点
		this.refs.myInput.focus()
	}
	render() {
		//  当组件插入到 DOM 后，ref 属性添加一个组件的引用于到 this.refs
		return (
			<div>
				<input type="text" ref="myInput" />
				<input
					type="button"
					value="点我输入框获取焦点"
					onClick={this.handleClick.bind(this)}
				/>
			</div>
		)
	}
}
